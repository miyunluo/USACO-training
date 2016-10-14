/*
 ID: miyunlu1
 PROG: milk6
 LANG: C++11
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x7fffffff
int cap[35][35],tcap[35][35],edge[1001][3];
int pre[35];
int N,M,maxFlow;

int BFS()
{
    //memset(pre, 0, sizeof(pre));
    for(int i = 0;i<35;++i) pre[i] = 0;
    int curr_cap[35];
    queue<int> que;
    que.push(1);
    pre[1] = -1;
    curr_cap[1] = INF;
    while(!que.empty())
    {
        int ind = que.front();que.pop();
        for(int i = 1;i<=N;++i)
            if(pre[i] == 0 && cap[ind][i] > 0)
            {
                curr_cap[i] = min(curr_cap[ind],cap[ind][i]);
                pre[i] = ind;
                que.push(i);
            }
    }
    if(pre[N] == 0) return -1;
    else return curr_cap[N];
}
int EK()
{
    int add, ans = 0;
    while((add = BFS()) != -1)
    {
        ans += add;
        int k = N;
        while(pre[k] != -1)
        {
            cap[pre[k]][k] -= add;
            cap[k][pre[k]] += add;
            k = pre[k];
        }
    }
    return ans;
}
int main()
{
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    cin >> N >> M;
    for(int i = 1;i<=M;++i)
    {
        int st,en,c;
        cin >> st >> en >> c;
        if(st != en)
        {
            cap[st][en] += c;
            tcap[st][en] += c;
            edge[i][0] = st;
            edge[i][1] = en;
            edge[i][2] = c;
        }
    }
    maxFlow = EK();
    if(maxFlow == 0){cout << 0<<' '<<0<<endl;return 0;}
    for(int i = 1;i<=M;++i)
        if(edge[i][2] == maxFlow)
        {
            cout << maxFlow <<' '<<1<<endl;
            cout << i<<endl;
            return 0;
        }
    vector<int> ans;
    for(int i= 1;i<=M;++i)
    {
        if(edge[i][2] > maxFlow)continue;
        if(edge[i][0] == edge[i][1])continue;
        for(int i = 1;i<=N;++i)
            for(int j = 1;j<=N;++j) cap[i][j] = tcap[i][j];
        cap[edge[i][0]][edge[i][1]] -= edge[i][2];
       
        int nflow = EK();
        if(maxFlow - nflow == edge[i][2]) ans.push_back(i);
    }
    
    cout << maxFlow <<' '<<ans.size()<<endl;
    for(auto i = 0;i<ans.size();++i) cout<<ans[i]<<endl;
    return 0;
}
//  Created on 16/5/3.