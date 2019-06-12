//
//  main.cpp
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//


#include "poj_1979_red_and_black.h"

int main(int argc, const char * argv[]) {
    while (scanf("%d%d", &W, &H)) {
        if(W == 0) break;
        getchar();
        
        for(int i = 0;i < H; i++){
            gets(tiles[i]);
        }
        
        solve();
    }
    
    return 0;
}
