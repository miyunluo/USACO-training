/*
 ID: miyunlu1
 PROG: snail
 LANG: C++11
 */
#include <iostream>
using namespace std;
int N,C;
int g[120][120];
int ans;

void DFS(int x,int y,int dir,int step)
{
    int stepu = step;
    switch(dir)
    {
        case 1:{ //up
            int tmpx = x;
            while(tmpx-1 >=0 && g[tmpx-1][y] != 1 && g[tmpx-1][y] != 2)
            {g[tmpx-1][y] = 2;--tmpx;++stepu;}
            if(tmpx-1 >=0 && g[tmpx-1][y] == 2)
            {
                ans = max(ans,stepu);
                int tx = tmpx;
                while(tx != x){g[tx][y] = 0;++tx;}
                return;
            }
            if(tmpx == 0 || (tmpx >0 && g[tmpx-1][y] == 1))
            {
                ans = max(ans,stepu); //每个case的这里加这么一句，因为die的情况除了踩到自己，还有遇到障碍或边但无路可走
                if(y-1 >=0 && g[tmpx][y-1] == 0)DFS(tmpx, y, 3, stepu);
                if(y+1 <N && g[tmpx][y+1] == 0) DFS(tmpx, y, 4, stepu);
                int tx = tmpx;
                while(tx != x){g[tx][y] = 0;++tx;}
            }
            
            break;
        }
        case 2:{ //down
            int tmpx = x;
            while(tmpx+1 <N && g[tmpx+1][y] != 1 && g[tmpx+1][y] != 2)
            {g[tmpx+1][y] = 2;++tmpx;++stepu;}
            if(tmpx+1 <N && g[tmpx+1][y] == 2)
            {
                ans = max(ans,stepu);
                int tx = tmpx;
                while(tx != x){g[tx][y] = 0;--tx;}
                return;
            }
            if(tmpx == N-1 || (tmpx <N-1 && g[tmpx+1][y] == 1))
            {
                ans = max(ans,stepu);
                if(y-1 >=0 && g[tmpx][y-1] == 0)DFS(tmpx, y, 3, stepu);
                if(y+1 <N && g[tmpx][y+1] == 0) DFS(tmpx, y, 4, stepu);
                int tx = tmpx;
                while(tx != x){g[tx][y] = 0;--tx;}
            }
            break;
        }
        case 3:{ // left
            int tmpy = y;
            while(tmpy-1 >=0 && g[x][tmpy-1] != 1 && g[x][tmpy-1] != 2)
            {g[x][tmpy-1] = 2;--tmpy;++stepu;}
            if(tmpy-1 >=0 && g[x][tmpy-1] == 2)
            {
                ans = max(ans,stepu);
                int ty = tmpy;
                while(ty != y){g[x][ty] = 0;++ty;}
                return;
            }
            if(tmpy == 0 || (tmpy >0 && g[x][tmpy-1] == 1))
            {
                ans = max(ans,stepu);
                if(x-1 >=0 && g[x-1][tmpy] == 0)DFS(x, tmpy, 1, stepu);
                if(x+1 <N && g[x+1][tmpy] == 0) DFS(x, tmpy, 2, stepu);
                int ty = tmpy;
                while(ty != y){g[x][ty] = 0;++ty;}
            }
            break;
        }
        case 4:{
            int tmpy = y;
            while(tmpy+1 < N && g[x][tmpy+1] != 1 && g[x][tmpy+1] != 2)
            {g[x][tmpy+1] = 2;++tmpy;++stepu;}
            if(tmpy+1 <N && g[x][tmpy+1] == 2)
            {
                ans = max(ans,stepu);
                int ty = tmpy;
                while(ty != y){g[x][ty] = 0;--ty;}
                return;
            }
            if(tmpy == N-1 || (tmpy <N-1 && g[x][tmpy+1] == 1))
            {
                ans = max(ans,stepu);
                if(x-1 >=0 && g[x-1][tmpy] == 0)DFS(x, tmpy, 1, stepu);
                if(x+1 <N && g[x+1][tmpy] == 0) DFS(x, tmpy, 2, stepu);
                int ty = tmpy;
                while(ty != y){g[x][ty] = 0;--ty;}
            }
            break;
        }
    }
}
int main()
{
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    cin >> N >> C;
    for(int i = 0;i<C;++i)
    {
        char L;int H;
        cin >> L >> H;
        g[H-1][L - 'A'] = 1; //1 means the hinder
    }
    g[0][0] = 2;
    if(g[0][1] == 0)DFS(0, 0, 4, 0);
    if(g[1][0] == 0)DFS(0, 0, 2, 0);
    cout << ans + 1<<endl;
    return 0;
}
//  Created on 16/5/8.
// dir/ 1 up/ 2 down/ 3 left/ 4 right