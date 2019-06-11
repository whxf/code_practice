//
//  main.cpp
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#include "poj_2386_lake_counting.h"

int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        for(int i = 0;i < n; i++){
            string tmp;
            cin >> tmp;
            for(int j = 0;j < m; j++){
                if(tmp[j] == 'W'){
                    field[i][j] =  1;
                }
                else{
                    field[i][j] =  0;
                }
            }
        }
        
        solve();
    }
    
    return 0;
}
