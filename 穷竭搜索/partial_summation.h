//
//  partial_summation.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/10.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef partial_summation_h
#define partial_summation_h

/*
 问题描述：
 判断是否存在若干数，使得和为k
 解题思路：
 依次判断a_i加或者不加，最后判断求和结果是不是k即可，时间复杂度是O(2^n)。
 */

#include <iostream>

#define MAX_IN 20

using namespace std;

int a[MAX_IN], n, k;

bool dfs(int i, int sum){
    if(i==n) return sum == k;
    if(dfs(i+1, sum)) return true;
    if(dfs(i+1, sum+a[i])) return true;
    return false;
}


void solve(){
    if(dfs(0, 0)) cout << "YES\n";
    else cout << "NO\n";
}

#endif /* partial_summation_h */
