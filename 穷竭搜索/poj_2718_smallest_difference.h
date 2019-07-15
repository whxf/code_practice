//
//  poj_2718_smallest_difference.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/7/15.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef poj_2718_smallest_difference_h
#define poj_2718_smallest_difference_h


/*
 题目描述：
 一组数，组成两个数字，h求最小h差
 解题思路：
 枚举所有可能
 */


#include<stdio.h>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int inputs[12];
int n;


void solve(){
    scanf("%d\n", &n);
    
    while(n--){
        // 输入
        memset(inputs,0,sizeof(inputs));
        char c;
        int cnt = 0;
        while((c=getchar())!='\n')
        {
            if(c!=' ')
                inputs[cnt++]=c-'0';
        }
        
        // 处理
        while(inputs[0]==0)
            next_permutation(inputs,inputs+cnt); // 获取数组的全排列
        
        int ans=INF;
        int mid=(cnt+1)/2; // 结果的两个数位数相近
        do{
            if(inputs[mid]){
                int x=inputs[0], y=inputs[mid];
                //计算数字的值
                for(int i=1;i<mid;i++)
                    x=x*10+inputs[i];
                for(int i=mid+1;i<cnt;i++)
                    y=y*10+inputs[i];
                // 更新最小差
                if(ans>abs(x-y))
                    ans=abs(x-y);
            }
        }while(next_permutation(inputs,inputs+cnt));// 获取下一个排列
        
        // 输出
        if(cnt==1)
            printf("%d\n",inputs[0]);
        else if(cnt==2)
            printf("%d\n",abs(inputs[1]-inputs[0]));
        else
            printf("%d\n", ans);
    }
}

#endif /* poj_2718_smallest_difference_h */
