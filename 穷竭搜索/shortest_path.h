//
//  shortest_path.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/11.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef shortest_path_h
#define shortest_path_h

/*
 题目描述：
 给定一个大小为N×M的迷宫。迷宫由通道和墙壁组成，每一步可以向邻接的上下
 左右四格的通道移动。请求出从起点到终点所需的最小步数。请注意，本题假定
 从起点一定可以移动到终点。
 ------------------------------
 示例输入：
 10 10
 #S######.#
 ......#..#
 .#.##.##.#
 .#........
 ##.##.####
 ....#....#
 .#######.#
 ....#.....
 .####.###.
 ....#...G#
 ------------------------------
 示例输出：
 22
 ------------------------------
 
 解题思路：
 详细思路见注释。
 
 知识点补充：
 pair 是 一种模版类型。每个pair可以存储两个值。这两种值无限制。也可以将
 自己写的struct的对象放进去。

 */

#include<string>
#include <iostream>
#include <queue>
#define MAX_IN 100
#define INF 0x7FFFFFFF

using namespace std;

typedef pair<int, int> P;

int n, m;
char field[MAX_IN][MAX_IN]; // 保存迷宫状态
int start_x, start_y, end_x, end_y; // 保存迷宫的入口、出口位置
int dx[4] ={1, 0, -1, 0}, dy[4] ={0, 1, 0, -1};  // 方向移动
int d[MAX_IN][MAX_IN]; // 保存各个位置的最短距离


int bfs(){
    // 队列，每次从队列前面的取
    queue<P> que;
    
    // 把所有位置初始化为INF，INF表示不可到达
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            d[i][j] = INF;
        }
    }
    
    // 把起点放入队列，然后初始化距离为0
    que.push(P(start_x, start_y));
    d[start_x][start_y] = 0;
    
    // 不断循环知道队列的长度为0
    while (que.size()) {
        // 取出队列最前面的元素
        P p = que.front();
        que.pop();
        
        // 如果已经是最后一个位置了就结束
        if(p.first == end_x && p.second == end_y)
            break;
        
        // 循环四个方向
        for(int i = 0;i < 4;i++){
            // 获取四个方向移动后的坐标
            int nx = p.first + dx[i] , ny = p.second + dy[i];
            
            // 判断坐标合法性，是否已经访问过（INF表示没访问），而且不是墙#
            if(nx >= 0 && nx < n && ny >= 0 && ny < m
               && d[nx][ny] == INF && field[nx][ny] != '#'){
                
                // 可以的话就加入队列，并更新距离
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
            

        }
    }
    
    return d[end_x][end_y];
}

void solve(){
    // find start and end
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j++){
            if(field[i][j] == 'S'){
                start_x = i;
                start_y = j;
            }
            else if(field[i][j] == 'G'){
                end_x = i;
                end_y = j;
            }
        }
    }
    
    // get shortest path
    int ret = bfs();
    cout << ret << '\n';
}
#endif /* shortest_path_h */
