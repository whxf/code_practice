//
//  poj_2386_lake_counting.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/10.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_2386_lake_counting_h
#define poj_2386_lake_counting_h

/*
 题目描述：
 有一个大小为N×M的园子，雨后积起了水。八连通的积水被认为是连在一起的。
 求园子里一共有多少水洼？
 
 Sample Input
 10 12
 W........WW.
 .WWW.....WWW
 ....WW...WW.
 .........WW.
 .........W..
 ..W......W..
 .W.W.....WW.
 W.W.W.....W.
 .W.W......W.
 ..W.......W.
 
 Sample Output
 3
 
 解题思路：
 从一个位置开始，不断把W及其周围的W用.代替，直到所有的W都被替换成.。
 首先进行替换W->1, .->0。从(0, 0)开始遍历，遇到1之后将自身置为0，
 然后采用深度优先搜索，8个方向对应8个状态转移，分别进行dfs。每个格子
 作为DFS的参数最多调用一次，因此时间复杂度为O(8nm)=O(nm)。
 */

#include<string>
#include <iostream>

#define MAX_IN 100

using namespace std;

int n, m, field[MAX_IN][MAX_IN];

void dfs(int x, int y){
    if(field[x][y] == 0) return;
    field[x][y] = 0;
    for(int i = -1; i<=1;i++){
        for(int j = -1; j<=1;j++){
            if((i == 0 && j == 0) ||
               (x+i < 0 || x+i >= n) ||
               (y+j < 0 || y+j >= m)){
                continue;
            }
            dfs(x+i, y+j);
        }
    }
}

void solve(){
    int cnt = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m;j++){
            if(field[i][j] == 1){
                cnt ++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}

#endif /* poj_2386_lake_counting_h */
