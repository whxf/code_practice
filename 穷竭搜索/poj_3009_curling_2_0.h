//
//  poj_3009_curling_2_0.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/28.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_3009_curling_2_0_h
#define poj_3009_curling_2_0_h


/*
 题目描述:
 一个很有趣的迷宫问题，只能朝一个方向直走，当撞到墙上时可以转弯，且那一块墙消失。
 Each line consists of w decimal numbers delimited by a space. The
 number describes the status of the corresponding square.
         0    vacant square
         1    block
         2    start position
         3    goal position
 The dataset for Fig. D-1 is as follows:
 6 6
 1 0 0 2 1 0
 1 1 0 0 0 0
 0 0 0 0 0 3
 0 0 0 0 0 0
 1 0 0 0 0 1
 0 1 1 1 1 1
 答案是: 4
 解题思路：
 从start位置开始便利每个方向直线上的block内容，每次在方向上前进1格：1）如果撞到墙
 就停止该方向遍历，然后以前一格为start重复dfs；2）遇到end停止遍历，更新step，保留
 最小step
 */

#include <iostream>
#define MAXN 25
#define MAX 0x7FFFFFFF

using namespace std;

int panel[MAXN][MAXN];
int step, steps; // 当前step，和记录的最小step
int w,h;
int dx[4] ={1, 0, -1, 0}, dy[4] ={0, 1, 0, -1};
int ex, ey;
int sx, sy;

void dfs(int x, int y){
    if (step > 10) return;
    
    for(int i = 0;i < 4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        bool is_ok = false;
        
        while(1){
            // 判断是否出棋盘
            if(nx < 0 || nx >= w || ny < 0 || ny >= h || panel[nx][ny] == 1){
                break;
            }
            is_ok = true;
            
            // 判断是否到达最终的位置，更新min step
            if(nx == ex && ny == ey){
                if(step < steps){
                    steps = step;
                    break;
                }
            }
            // 继续向该方向移动
            nx += dx[i];
            ny += dy[i];
        }// 直到移动到最终的位置，撞墙or出界
        
        // 如果是撞墙进行下一步操作
        if(panel[nx][ny] == 1 && is_ok){
            // step + 1, 然后撞到的墙变为0
            step++;
            panel[nx][ny] = 0;
            // dfs上一个位置（墙的前一个位置）
            dfs(nx-dx[i],ny-dy[i]);
            // 数据恢复
            step--;
            panel[nx][ny] = 1;
        }
    }
}

void solve(){
    while (cin >> w >> h) {
        if(w == 0){
            break;
        }
        memset(panel,0,sizeof(panel));
        //输入数据
        for(int i = 0;i < h; i++){
            for(int j = 0;j < w;j++){
                cin >> panel[j][i];
                if(panel[j][i] == 2){
                    sx = j;
                    sy = i;
                }
                if(panel[j][i] == 3){
                    ex = j;
                    ey = i;
                }
            }
        }
        step = 1;
        steps = MAX;
        dfs(sx, sy);
        if(steps > 10) cout << -1 << '\n';
        else cout << steps << '\n';
    }
}


#endif /* poj_3009_curling_2_0_h */
