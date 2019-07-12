//
//  poj_1979_red_and_black.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/12.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_1979_red_and_black_h
#define poj_1979_red_and_black_h

/*
 题目描述：
 There is a rectangular room, covered with square tiles.
 Each tile is colored either red or black. A man is stand-
 -ing on a black tile. From a tile, he can move to one of
 four adjacent tiles. But he can't move on red tiles, he can
 move only on black tiles.
 Write a program to count the number of black tiles which
 he can reach by repeating the moves described above.
 解题思路：
 参考了lake counting的方法，将man能到的地方用@染色，最后数一下tiles
 中@的总数。
 */

#include <stdio.h>
#define MAX_IN 25

int W, H;
char tiles[MAX_IN][MAX_IN];
int man_x, man_y;
int dx[4] ={1, 0, -1, 0}, dy[4] ={0, 1, 0, -1};

void dfs(int x, int y){
    tiles[x][y] = '@';
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i] , ny = y + dy[i];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W
           && tiles[nx][ny] == '.'){
            dfs(nx, ny);
        }
    }
}

void solve(){
    for(int i = 0; i < H;i ++){
        for(int j = 0;j < W;j++){
            if(tiles[i][j] == '@'){
                man_x = i;
                man_y = j;
                break;
            }
        }
    }
    
    dfs(man_x, man_y);
    
    int ret = 0;
    
    for(int i = 0; i < H;i ++){
        for(int j = 0;j < W;j++){
            if(tiles[i][j] == '@'){
                ret ++;
            }
        }
    }
    
    printf("%d\n", ret);
}

#endif /* poj_1979_red_and_black_h */
