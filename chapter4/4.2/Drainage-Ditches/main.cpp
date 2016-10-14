/*
 ID: miyunlu1
 PROG: ditch
 LANG: C++11
 */
#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x7fffffff;
int N,M;
int cap[201][201];
int flow[201];
int pre[201];

int BFS(int src, int des)
{
    queue<int> que;
    for(int i =1;i<=M;++i) pre[i] = -1;
    flow[src] = INF;
    pre[src] = 0;
    que.push(src);
    while(!que.empty())
    {
        int ind = que.front();que.pop();
        if(ind == des) break;
        
        for(int i = 1;i<=M;++i)
        {
            if(pre[i] == -1 && cap[ind][i] >0)
            {
                pre[i] = ind;
                flow[i] = min(cap[ind][i], flow[ind]);
                que.push(i);
            }
        }
    }
    if(pre[des] == -1) return -1;
    else return flow[des];
}

int maxFlow(int src, int des)
{
    int sum = 0;
    int increas = 0;
    while((increas = BFS(src, des)) != -1)
    {
        int k = des;
        while(k != src)
        {
            int last = pre[k];
            cap[last][k] -= increas;
            cap[k][last] += increas;
            k = last;
        }
        sum += increas;
    }
     return sum;
}

int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    cin>> N >> M;
    for(int i = 0;i<N;++i)
    {
        int start, end, c;
        cin >> start >> end >> c;
        if(start == end) continue;
        cap[start][end] += c;
    }
    cout << maxFlow(1,M)<<endl;
    return 0;
}