/*
 ID: miyunlu1
 PROG: milk3
 LANG: C++11
 */
#include <iostream>
#include <cstring>
using namespace std;

int cap[3]; //容量
int ans[22] = {0}; //答案的标记数组
bool vis[22][22][22] = {0}; //状态的标记数组

void DFS(int a[])
{
    if(vis[a[0]][a[1]][a[2]]) return;
    vis[a[0]][a[1]][a[2]] = true;
    if(a[0] == 0) ans[a[2]] = 1;
    //6种倒牛奶的方案
    for(int i = 0;i<3;++i)
        for(int j = 0;j<3;++j)
        {
            if(i != j)
            {
                int b[3];
                memcpy(b, a, sizeof(int)*3);
                if(a[i] > 0 && a[j] < cap[j])
                {
                    int carry = min(a[i],(cap[j]-a[j]));
                    b[i] -= carry;
                    b[j] += carry;
                    DFS(b);
                }
            }
        }
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    cin >> cap[0] >> cap[1] >> cap[2];
    int a[] = {0,0,cap[2]};
    DFS(a);
    for(int i=0;i<cap[2];++i)
        if(ans[i] != 0) cout << i<<' ';
    cout << cap[2]; //擦，答案最后多输出一个空格都不行！！！！！！
    cout <<endl;
    return 0;
}