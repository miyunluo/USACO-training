/*
 ID: miyunlu1
 PROG: schlnet
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int G[101][101],shrink[101][101];
vector<int> g[101],gt[101];
int N,B;
int vis[101],uni[101];
int degreeIn[101],degreeOut[101];
void DFS(int ind)
{
    vis[ind] = true;
    for(int i = 0;i<g[ind].size();++i)
    {
        if(!vis[g[ind][i]])
        DFS(g[ind][i]);
    }
}

void RDFS(int ind)
{
    uni[ind] = B;
    for(int i = 0;i<gt[ind].size();++i)
    {
        if(vis[ gt[ind][i] ] && !uni[ gt[ind][i]])
        RDFS(gt[ind][i]);
    }
}

void strongCon()
{
    for(int i = 1;i<=N;++i)
        if(!uni[i])
        {
            memset(vis,false,sizeof(vis));
            DFS(i);
            ++B;
            RDFS(i);
        }
}

void solution()
{
    strongCon();
    for(int i = 1;i<=N;++i)
        for(int j = 1;j<=N;++j)
        {
            if(i == j)continue;
            if(uni[i] == uni[j])continue;
            if(G[i][j])
            {
                shrink[uni[i]][uni[j]] = 1;
                degreeOut[uni[i]] = 1;
                degreeIn[uni[j]] = 1;
            }
        }
    int inum = 0,onum = 0;
    for(int i = 1;i<=B;++i) if(degreeIn[i] == 0)++inum;
    for(int i = 1;i<=B;++i) if(degreeOut[i] == 0)++onum;
    if(B == 1){cout<< 1 <<endl << 0<<endl;}
    else{
        cout << inum << endl <<max(inum,onum)<<endl;
    }
}
int main()
{
    freopen("schlnet.in", "r", stdin);
    freopen("schlnet.out", "w", stdout);
    cin >> N;
    for(int i = 1;i<=N;++i)
    {
        int p;
        cin >> p;
        while(p)
        {
            g[i].push_back(p);
            G[i][p] = 1;
            gt[p].push_back(i);
            cin >> p;
        }
    }
    solution();
    return 0;
}
//  Created on 16/5/19.
/*
 5
 2 4 3 0
 4 5 0
 0
 0
 1 0
*/