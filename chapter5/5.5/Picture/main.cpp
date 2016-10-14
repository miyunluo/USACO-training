/*
 ID: miyunlu1
 PROG: picture
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
struct Edge{
    int y;
    int x1,x2;
    bool front;
    Edge(int Y=0,int X1=0,int X2=0,bool f=false)
    {y = Y,x1 = X1,x2 = X2,front = f;}
    bool operator <(const Edge & another_edge)const
    {return y < another_edge.y || (y == another_edge.y && front);}
};
Edge edgeRow[20010],edgeCol[20010];

int cnt[40010] = {0};
int N;
long solution(Edge edges[])
{
    long ans = 0;
    memset(cnt, 0, sizeof cnt);
    sort(edges,edges+2*N);
    for(int i = 0;i<2*N;++i)
    {
        Edge e = edges[i];
        for(int j = e.x1;j<e.x2;++j)
        {
            if(e.front) ++cnt[j];
            else --cnt[j];
            
            if((e.front && cnt[j] == 1) || (!e.front && cnt[j] == 0)) ++ans;
        }
    }
    return ans;
}

int main()
{
    freopen("picture.in", "r", stdin);
    freopen("picture.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
    {
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        lx += 10000, ly += 10000, rx += 10000, ry += 10000;
        
        edgeRow[i*2] = Edge(ly,lx,rx,true);
        edgeRow[i*2+1] = Edge(ry,lx,rx,false);
        edgeCol[i*2] = Edge(lx,ly,ry,true);
        edgeCol[i*2+1] = Edge(rx,ly,ry,false);
    }
    long ANS = solution(edgeRow) + solution(edgeCol);
    cout << ANS << endl;
    return 0;
}

//  Picture
//  Created on 16/9/16.



