/*
 ID: miyunlu1
 PROG: fc
 LANG: C++11
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    double x,y,cosin;  
};
node point[10005];
int N;
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
bool cmp(node a,node b)
{
    return a.cosin < b.cosin;
}
bool left(node ff,node f,node n)
{
    double x1,x2,y1,y2;
    x1 = f.x - ff.x, y1 = f.y - ff.y;
    x2 = n.x - ff.x, y2 = n.y - ff.y;
    
    if(x1*y2 - x2*y1 > -0.00001)return true;
    else return false;
}
double Graham()
{
    int num, st[10005];
    double ans = 0;
    st[1] = 0,st[2] = 1,num = 2;
    for(int i = 2;i<N;++i)
    {
        while(!(left(point[st[num-1]], point[st[num]],point[i]))) --num;
        st[++num] = i;
    }
    st[num+1] = 0;
    for(int i = 1;i<=num;++i) ans += dis(point[st[i]],point[st[i+1]]);
    return ans;
}
int main()
{
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    cin >> N;
    int k = 1;
    for(int i = 1;i<=N;++i)
    {
        cin >> point[i].x >> point[i].y;
        if(point[i].x < point[k].x) k = i;
        else if(abs(point[i].x - point[k].x)<0.00001 && point[i].y < point[k].y) k = i;
    }
    point[0] = point[k];
    point[k] = point[N];
    for(int i = 1;i<N;++i) point[i].cosin = (point[i].y - point[0].y)/dis(point[i],point[0]);
    sort(point+1,point+N,cmp);
    printf("%.2lf\n",Graham());
    return 0;
}