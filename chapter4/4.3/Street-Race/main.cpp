/*
 ID: miyunlu1
 PROG: race3
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int g[50][50];
int table[50][50],duplicate[50][50];
int vis[50],mark[50];
vector<int> ans1,ans2;
//---------------------------------------------------
void BFS(int ind)
{
    queue<int> que;
    que.push(0);
    vis[0] = 1;
    while(!que.empty())
    {
        int node = que.front();que.pop();
        
        int k = 0;
        while(g[node][k] != -2)
        {
            if(vis[g[node][k]] == 0 && g[node][k] != ind)
            {vis[g[node][k]] = 1;que.push(g[node][k]);}
            ++k;
        }
    }
}

void mustPass(int maxN)
{
    for(int i = 1;i<maxN;++i)
    {
        memset(vis, 0, sizeof(vis));
        BFS(i);
        if(vis[maxN] == 0) ans1.push_back(i);
    }
}
//-----------------------------------------------------
void floyd(int maxN, int ind)
{
    memset(duplicate, 0, sizeof(duplicate));
    for(int i= 0;i<=maxN;++i)
    {
        if(i == ind) continue;
        for(int j=0;j<=maxN;++j)
        {
            if(j == ind || i == j) continue;
            duplicate[i][j] = table[i][j];
        }
    }
    for(int k = 0;k<=maxN;++k)
        for(int i = 0;i<=maxN;++i)
            for(int j =0;j<=maxN;++j)
                if(duplicate[i][j] == 1 || (duplicate[i][k]==1 && duplicate[k][j]==1))
                   duplicate[i][j] = 1;
}

void Divide(int maxN)
{
    for(auto i = 0;i<ans1.size();++i)
    {
        floyd(maxN, ans1[i]);
        memset(mark, 0, sizeof(mark));
        int init = 1;
        for(int j = 0;j<=maxN;++j)
        {
            if(j == ans1[i])continue;
            if(mark[j] == 0)
            {
                mark[j] = init;
                for(int k = 0;k<=maxN;++k)
                {
                    if(k == ans1[i])continue;
                    if(duplicate[j][k] == 1 || duplicate[k][j] == 1)mark[k] = init;
                }
                ++init;
            }
            else{
                for(int k = 0;k<=maxN;++k){
                    if(k == ans1[i])continue;
                    if(duplicate[j][k] == 1 || duplicate[k][j] == 1){
                        if(mark[k] == 0)mark[k] = mark[j];
                        else mark[k] = min(mark[k],mark[j]);
                    }
                }
            }
        }
        if(mark[maxN] != 1 )
        {
            int num = 0;
            for(int k =0;k<=maxN;++k)
                if(table[ans1[i]][k] == 1 && mark[k] == 1)++num;
            if(num == 0) ans2.push_back(ans1[i]);
        }
    }
}
//--------------------------------------------------------------
int main()
{
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    int ind = 0, curr = 0, tmp;
    while(cin >> tmp)
    {
        if(tmp == -1)break;
        if(tmp == -2)
        {
            g[curr][ind] = tmp;
            ++curr;
            ind = 0;
            continue;
        }
        if(tmp == curr) continue;
        g[curr][ind++] = tmp;
        table[curr][tmp] = 1;
    }
    --curr;
    mustPass(curr);
    cout << ans1.size();
    for(auto i = 0;i<ans1.size();++i) cout <<' '<<ans1[i];
    cout << endl;
    Divide(curr);
    cout << ans2.size();
    for(auto i = 0;i<ans2.size();++i) cout <<' '<<ans2[i];
    cout << endl;
    return 0;
}
//  Street Race 街道赛跑
//  Created on 16/4/27.
/*
 1 2 -2
 3 -2
 3 -2
 5 4 -2
 6 4 -2
 6 -2
 7 8 -2
 9 -2
 5 9 -2
 -2
 -1
 
 
 1 -2
 2 -2
 3 -2
 4 -2
 5 -2
 6 -2
 7 -2
 8 -2
 9 -2
 10 -2
 11 -2
 12 -2
 13 -2
 14 -2
 15 -2
 16 -2
 17 -2
 18 -2
 19 -2
 20 -2
 21 -2
 22 -2
 23 -2
 24 -2
 25 -2
 26 -2
 27 -2
 28 -2
 29 -2
 30 -2
 31 -2
 32 -2
 33 -2
 34 -2
 35 -2
 36 -2
 37 -2
 38 -2
 39 -2
 40 -2
 41 -2
 42 -2
 43 -2
 44 -2
 45 -2
 46 -2
 47 4 -2
 48 -2
 49 -2
 -2
 -1
 */

