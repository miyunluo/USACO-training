/*
 ID: miyunlu1
 PROG: concom
 LANG: C++11
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool flag[101];
bool control[101];
int table[101][101];
int kongu[101];
int N,threshold;

//dfs学习了。。。只要是自己控制的公司，他控的股就往自己控的股里加
void DFS(int x)
{
    if(flag[x])return;
    flag[x] = true;
    for(int i =1;i<=N;++i)
    {
        kongu[i] += table[x][i];
        if(kongu[i] > 50)
        {control[i] = true;DFS(i);}
    }
}

int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        table[a][b] = c;
        threshold = max(max(a,b),threshold);
    }
    N = threshold;
    for(int i =1;i<=N;++i)
    {
        fill_n(flag,N+1,false);
        fill_n(control,N+1,false);
        fill_n(kongu,N+1,0);
        DFS(i);
        for(int j = 1;j<=N;++j)
        {
            if(control[j] && i != j)cout << i << ' ' <<j <<endl;
        }
    }
    return 0;
}