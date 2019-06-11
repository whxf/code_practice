//
//  main.cpp
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#include "shortest_path.h"

int main(int argc, const char * argv[]) {
    while (cin >> n >> m) {
        for(int i = 0;i < n; i++){
            string tmp;
            cin >> tmp;
            for(int j = 0;j < m; j++){
                field[i][j] =  tmp[j];
            }
        }
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                cout<<field[i][j];
            }
            cout << '\n';
        }
        solve();
    }
    
    return 0;
}
