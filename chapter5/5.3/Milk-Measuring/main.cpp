/*
 ID: miyunlu1
 PROG: milk4
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int Q,N;
int cap[102];
int choose[102];
bool f[100002];
void DFS(int deep,vector<int> v,int ind)
{
    if(v.size() == deep)
    {
        memset(f,false,sizeof(f));
        f[0] = true;
        for(int i = 0;i<v.size();++i)
            for(int j = 1;j<=Q;++j)
                if(j-v[i] >= 0)
                    f[j] = f[j] || f[j-v[i]];
        if(f[Q])
        {
            cout << v.size();
            for(int i = 0;i<v.size();++i)cout <<' '<<v[i];
            cout << endl;
            exit(0);
        }
        return;
    }
    vector<int> vp = v;
    v.push_back(cap[ind]);
    if(ind+1 <=N)
    {
        DFS(deep, v,ind+1);
        DFS(deep,vp,ind+1);
    }
}
int main()
{
    freopen("milk4.in", "r", stdin);
    freopen("milk4.out", "w", stdout);
    cin >> Q >> N;
    for(int i = 0;i<N;++i)cin >> cap[i];
    sort(cap,cap+N);
    for(int i = 1;i<=N;++i)
    {
        vector<int> vct;
        vct.clear();
        DFS(i,vct,0);
    }
    return 0;
}
// 2016 05 16
/*
 59
 3
 7
 11
 13
 */