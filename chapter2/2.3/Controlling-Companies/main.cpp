/*
 ID: miyunlu1
 PROG: concom
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
using namespace std;
//想了很久怎么用树解决，果然是oj中毒太深了
//毫不犹豫的的用for循环啊啊啊啊啊啊啊啊啊啊啊，keep it simple stupid.
//真不爽
struct node{
    int x,y;
    node(){x = y = 0;}
};
node arry[10001];
int table[101][101];
bool vis[101][101] = {false};
int N,maxnum,cont;

bool cmp(const node &a,const node &b)
{
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    cin >> N;
    for(int i=0;i<N;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        maxnum = max(max(a,b),maxnum);
        table[a][b] = c;
    }
    N = maxnum;
    for(int i = 0;i<=N;++i) vis[i][i] = true;
    
    for(int i=1;i<=N;++i)
        for(int j = 1;j<=N;++j)
            if(!vis[i][j] && table[i][j] > 50)
            {
                ++cont;arry[cont].x = i;arry[cont].y = j;
                vis[i][j] = true;
            }

    for(;;)
    {
        bool find = false;
        for(int i = 1;i<=N;++i)
            for(int k = 1;k<=N;++k)
            {
                int sum = 0;
                if(!vis[i][k])
                {
                    for(int j = 1;j<=N;++j)
                        if(vis[i][j]) sum += table[j][k];
                }
                if(sum > 50)
                {
                    find = true;
                    ++cont;arry[cont].x = i;arry[cont].y = k;
                    vis[i][k] = true;
                }
            }
        if(!find) break;
    }
    
    sort(arry,arry+cont+1,cmp);
    
    for(int i = 1;i<=cont;++i)
    {
        cout << arry[i].x<<' '<<arry[i].y<<endl;
    }
    return 0;
    
}
