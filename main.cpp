//
//  main.cpp
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#include <iostream>
#include "poj_1852_ants.h"

int main(int argc, const char * argv[]) {
    while (cin >> L >> n) {
        for(int i = 0;i < n; i++){
            cin >> x[i];
        }
        
        solve();
    }
}
