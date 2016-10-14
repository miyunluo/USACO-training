/*
 ID: miyunlu1
 PROG: telecow
 LANG: C++11
 */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,c1,c2;
vector<int> g[101];
int G[101][101];
int vis[101],pre[101],dele[101];
int flow;
vector<int> ans;
bool BFS()
{
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    queue<int> que;que.push(c1);
    vis[c1] = 1;
    while(!que.empty())
    {
        int tmp = que.front();que.pop();
        for(int i = 0;i<g[tmp].size();++i)
            if(!dele[g[tmp][i]] && !vis[g[tmp][i]]){
                vis[g[tmp][i]] = 1;
                pre[g[tmp][i]] = tmp;
                que.push(g[tmp][i]);
            }
    }
    if(pre[c2] == 0)  return false;
    else{
        int k = pre[c2];
        while(k != c1)
        {
            dele[k] = 1;
            k = pre[k];
        }
        return true;
    }
}
int main()
{
    freopen("telecow.in", "r", stdin);
    freopen("telecow.out", "w", stdout);
    cin >> N >> M >> c1 >> c2;
    for(int i = 0;i<M;++i)
    {
        int n1,n2;
        cin >> n1 >> n2;
        g[n1].push_back(n2);g[n2].push_back(n1);
        G[n1][n2] = G[n2][n1] = 1; 
    }
    while(BFS()) ++ flow;
    for(int i = 1;i<=N;++i)
    {
        if(ans.size() == flow)break;
        if(i == c1 || i == c2)continue;
        memset(dele,0,sizeof(dele));
        dele[i] = 1;
        for(int j = 0;j<ans.size();++j)dele[ans[j]] = 1;
        int nflow = 0;
        while(BFS()) ++nflow;
        if(nflow +ans.size()+1 == flow)ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size()<<endl;
    cout <<ans[0];
    for(int i = 1;i<ans.size();++i)cout <<' '<<ans[i];
    cout << endl;
    return 0;
}
//  Created on 16/5/21.
/*
 3 2 1 2
 1 3
 2 3
 
 20 26 1 2
 1 9
 1 17
 1 19
 2 6
 2 9
 2 14
 3 15
 3 16
 3 18
 4 8
 5 6
 5 7
 5 12
 5 17
 6 7
 6 19
 7 13
 7 14
 7 15
 9 12
 9 14
 10 14
 11 12
 12 17
 13 15
 15 17
*/