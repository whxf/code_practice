//
//  poj_3187_backward _digit _sums.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/7/16.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_3187_backward__digit__sums_h
#define poj_3187_backward__digit__sums_h

/*
 题目描述：
 FJ and his cows enjoy playing a mental game. They write down the
 numbers from 1 to N (1 <= N <= 10) in a certain order and then
 sum adjacent numbers to produce a new list with one fewer number.
 They repeat this until only a single number is left. For example,
 one instance of the game (when N=4) might go like this:
 3   1   2   4
 4   3   6
 7   9
 16
 Behind FJ's back, the cows have started playing a more difficult
 game, in which they try to determine the starting sequence from
 only the final total and the number N. Unfortunately, the game is
 a bit above FJ's mental arithmetic capabilities.
 
 Write a program to help FJ play the game and keep up with the cows.
 
 Sample Input
 4 16
 Sample Output
 3 1 2 4
 
 解题思路：
 暴力枚举所有的排序，计算sum。注意事项有：
 1. N个数为 1-N
 2. 最后的输出没有 \n
 3. 可以先打表存储所有的杨辉三角参数
 */


#include <iostream>
#include<algorithm>

using namespace std;
int n,sum;

int cnt[12][12];
int arr[12];

void solve(){
    // 存储杨辉三角参数
    memset(cnt, 0, sizeof(cnt));
    cnt[1][1] = 1;
    for(int i = 2; i <= 10; i++){
        for(int j = 1; j <= i; j++){
            cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j];
        }
    }
    
    while(cin >> n >> sum){
        for(int i = 1; i <= n;i++){
            arr[i] = i;
        }
        do{
            int ans = 0;
            for(int i = 1; i <= n;i++){
                ans += arr[i] * cnt[n][i];
            }
            if(ans == sum){
                break;
            }
            
        }while (next_permutation(arr+1,arr+n+1));
        for(int i = 1;i <= n;i++){
            cout  << arr[i]<< ' ';
        }
    }
}

#endif /* poj_3187_backward__digit__sums_h */
