/*
题目简述：
有一些奶牛，每只奶牛负责一个时间段。问覆盖完全部的时间段最少需要多少只奶牛。
若不能全部覆盖，输出-1.

解题思路：
间覆盖的问题，将所有的区间排序，设置每次的start范围要求，如果<=说明满足，则
去end的max更新；否则说明出现空缺区间不能满足需求。
*/
#include <iostream>
#include <algorithm>
using namespace std;


int n, t;

typedef struct
{
    int startp;
    int endp;
} Node;

Node nodes[25005];


bool cmp(Node a, Node b)
{
    if(a.startp != b.startp)
        return a.startp < b.startp;
    return a.endp < b.endp;
}

void get_num()
{
    int cnt  = 0;
    int end_point = 0;
    int index = 0;

    while(end_point < t)
    {
        int begin_point = end_point + 1;
        for ( int i = index; i < n; i++)
        {
            if(nodes[i].startp <= begin_point)
            {
                if(nodes[i].endp >= begin_point)
                {
                    end_point = max(end_point, nodes[i].endp);
                }
            }
            else
            {
                index = i;
                break;
            }
        }

        if(begin_point > end_point)
        {
            cout << "-1\n";
            return;
        }
        else
        {
            cnt += 1;
        }
    }

    cout << cnt << '\n' ;
    return;
}

void solve()
{
    while(cin >> n >> t)
    {
        for ( int i = 0; i < n; i++)
        {
            cin >> nodes[i].startp >> nodes[i].endp;
        }

        sort(nodes, nodes + n, cmp);

        get_num();
    }
}
