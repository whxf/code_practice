//
//  longest_circumference_of_triangle.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef longest_circumference_of_triangle_h
#define longest_circumference_of_triangle_h

/*
 题目简述：
 给定由一些正数（代表长度）组成的数组A，返回由其中
 三个长度组成的、面积不为零的三角形的最大周长。如果
 不能形成任何面积不为零的三角形，返回 0。
 
 思路整理：
 1. 另一种方法是直接嵌套循环，时间复杂度是O(n)^3
 2. 优化后的时间复杂度是O(nlogn)，现将边排序，然
 后直接判断连续的三个是否满足两个小边之和大于大
 边。
 3. 为什么不用判断之后的？如果连续的三个不满足之后
 的(a[i], a[i-2], a[i-3]更不可能满足，因此
 只用判断前三个即可。而且这样直接可以找到最大的
 边。
 */

#include<algorithm>
#define MAX_IN 100

using namespace std;
int n, a[MAX_IN];

int solve(){
    sort(a, a + n);
    for(int i = n - 3; i >= 0; i--){
        if(a[i] + a[i+1] > a[i+2]){
            return a[i] + a[i+1] + a[i+2];
        }
    }
    return 0;
}

#endif /* longest_circumference_of_triangle_h */
