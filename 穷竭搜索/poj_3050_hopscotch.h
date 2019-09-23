/*
题目描述：
给定一个5*5的地图，每个格子上有一个数字。从一个格子出发（上下左右4个方向），
走5步将数字连起来可以构造出一个6位数。问该地图可以构造出多少个不同的6位数。

解题思路：
可以对每个格子做深度优先遍历，构造出所有数字，使用了set来保存已构造出的数字，
结果就是set中的元素个数。
*/

#include <iostream>
#include<set>
#include<string>

using namespace std;

set<int> s;
int dx[4] ={1, 0, -1, 0}, dy[4] ={0, 1, 0, -1};
int panel[5][5];


void dfs(int x, int y, int num, int route){
    if(num == 5){
        s.insert(route);
        return;
    }
    for (int d = 0; d<4;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5){
            continue; // 注意这里不能break
        }

        dfs(nx, ny, num + 1, route * 10 + panel[nx][ny]);
    }
}

void solve()
{

    for( int i = 0;i < 5;i++){
        for (int j = 0; j< 5;j++){
            cin >> panel[i][j];
        }
    }
    for( int i = 0;i < 5;i++){
        for (int j = 0; j< 5;j++){
            dfs(i,j,0,panel[i][j]);
        }
    }

    cout << s.size() << '\n';

}