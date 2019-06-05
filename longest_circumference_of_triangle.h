//
//  longest_circumference_of_triangle.h
//  挑战程序设计竞赛
//
//  Created by 李熙 on 2019/6/5.
//  Copyright © 2019 李熙. All rights reserved.
//

#ifndef longest_circumference_of_triangle_h
#define longest_circumference_of_triangle_h


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
