//
//  poj_3669_meteor_shower.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/7/12.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_3669_meteor_shower_h
#define poj_3669_meteor_shower_h

/*
 题目描述：
 流星雨即将攻击地球，当然数目是有限的，共n个，攻击到某个点时将会使该点及其
 上下左右四个点都被摧毁。一个女的，不想被击中啊，就跑啊。她要在地球上找到一
 个地方让她能够度过灾难。把整个地图看作一张二维表，设该女孩在原点。其中输入
 第一行为流星个数n。接下来n行，每行3个值，x,y,t。代表着（x,y）这一点将在
 t时间后接受流星的宠幸。输出为这个女的逃命的最短时间。如果注定将与流星为伴，
 那就输出-1。
 解题思路：
 利用bfs的思路，需要注意的是，输入的时候，同时把相邻位置的t修改，方便之后
 的操作。解题思路详见代码注释。
 */

#include <iostream>
#include <queue>
#define MAXN 305
#define MAX_M 50000
#define MAX 0x7F7F7F7F

using namespace std;

typedef pair<int, int> P;
int m;
int panel[MAXN][MAXN]; // 记录各个位置的被袭击时间
int d[MAXN][MAXN]; // 记录走得次数
int dx[5] ={1, 0, -1, 0, 0}, dy[5] ={0, 1, 0, -1, 0};


int bfs(){
    if(panel[0][0] == 0) return -1;
    
    queue<P> que;
    que.push(P(0,0));
    d[0][0] = 0; // 开始位置的d定义为0
    int ans=-1; // 最终答案
    
    while(!que.empty()){
        P p = que.front();
        que.pop();
        
        // 如果当前位置为INF，也就是爆炸用于都不会影响到的地方
        // 当前位置的d就是最终的ans
        if(panel[p.first][p.second] ==  MAX) {
            ans = d[p.first][p.second];
            break;
        }
        
        // 没有停止，继续走四个方向
        for(int i = 0;i < 4;i++){
            // 四个方向的坐标
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx >= 0 && ny >=0 // 符合标准
               && d[nx][ny] == MAX // 没被访问过
               && panel[nx][ny] > d[p.first][p.second]+1) {
                // panel预计爆炸的点是当前时间+1之后的时间
                // 也就是，保证走到下一个之后，下一个时刻不会被袭击
                
                // 目前点（nx，ny）的d等于上一个位置加一
                d[nx][ny]=d[p.first][p.second]+1;
                // 将新点push到队列中
                que.push(P(nx,ny));
            }

        }
    }
    
    return ans;
}


void solve(){
    // 初始化为-1，0代表最开始就会被袭击
    memset(panel, MAX, sizeof(panel));
    memset(d, MAX,sizeof(d));

    // 输入
    cin >> m;
    for(int i = 0;i < m;i++){
        int x, y, t;
        cin >> x >> y >> t;
        // 更新当前位置和周围的位置
        // 理解为t时刻当前位置会被袭击，周围的4个位置也会被袭击，因此更新
        // 更新需要选择最小的时间更新
        for(int j = 0; j < 5; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 0 && ny >= 0){
                panel[nx][ny] = min(t, panel[nx][ny]);
            }
        }
    }
    cout << bfs() << '\n';
}

#endif /* poj_3669_meteor_shower_h */
