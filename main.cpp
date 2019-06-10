//
//  main.cpp
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#include <iostream>
#include "partial_summation.h"

int main(int argc, const char * argv[]) {
    while (cin >> n >> k) {
        for(int i = 0;i < n; i++){
            cin >> a[i];
        }
        solve();
    }
}
