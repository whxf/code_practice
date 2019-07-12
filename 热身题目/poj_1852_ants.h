//
//  poj_1852_ants.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_1852_ants_h
#define poj_1852_ants_h

/*
 问题描述：
 An army of ants walk on a horizontal pole of length l cm,
 each with a constant speed of 1 cm/s. When a walking ant
 reaches an end of the pole, it immediatelly falls off it.
 When two ants meet they turn back and start walking in
 opposite directions. We know the original positions of
 ants on the pole, unfortunately, we do not know the dire-
 ctions in which the ants are walking. Your task is to
 compute the earliest and the latest possible times needed
 for all ants to fall off the pole.
 
 解题思路：
 因为蚂蚁都是一样的，所以当两只蚂蚁相遇时转向跟没转向没什么区别。因此，
 当蚂蚁相遇之后，可以视为蚂蚁方向不变，两个蚂蚁继续向前走。所以最短时间
 就是所有蚂蚁距端点最近距离的最大值，最长时间就是所有蚂蚁距端点最远距离
 的最大值。 
 */

#include <iostream>

#define MAX_IN 1000000
#define MAXN 0x7FFFFFFF


int L, n, x[MAX_IN];

using namespace std;

void solve(){
    int max_time = 0, min_time = 0;
    
    int mid = L/2;
    for(int i = 0; i < n; i++){
        if(x[i] > mid){
            min_time = max(L - x[i], min_time);
            max_time = max(x[i], max_time);
        }
        else{
            min_time = max(x[i], min_time);
            max_time = max(L - x[i], max_time);
        }
    }
    
    cout << min_time << ' ' << max_time << '\n';
    
}


#endif /* poj_1852_ants_h */
