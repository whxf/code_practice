//
//  get_all_permutation.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/12.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef get_all_permutation_h
#define get_all_permutation_h

/*
 说明：
 获取数组的所有排列组合，可使用C++标准库next_permutation辅助实现。
 */


#include <cstdio>
#include <algorithm>

using namespace std;

// STL next permutation base idea
int next_permutation(int *begin, int *end)
{
    int *i=begin, *j, *k;
    if (i==end || ++i==end) return 0;   // 0 or 1 element, no next permutation
    for (i=end-1; i!=begin;) {
        j = i--;    // find last increasing pair (i,j)
        if (!(*i < *j)) continue;
        // find last k which not less than i,
        for (k=end; !(*i < *(--k)););
        iter_swap(i,k);
        // now the range [j,end) is in descending order
        reverse(j,end);
        return 1;
    }
    // current is in descending order
    reverse(begin,end);
    return 0;
}

void all_permutation(int arr[], int n)
{
    sort(arr,arr+n);    // sort arr[] in ascending order
    do{
        for(int i=0; i<n; printf("%d ",arr[i++]));
        printf("\n");
    }while(next_permutation(arr,arr+n));  // get next permutation
}

#endif /* get_all_permutation_h */
