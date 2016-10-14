/*
 ID: miyunlu1
 PROG: starry
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int ,int> Pair;
int H,L;//行 列
char g[101][101];//图
int vis[101][101];//访问
int snum[501];//数量
string state[501];//状态
int scope[502][4];//范围 up down lf rt
char mark[502];//标记
int curr;
char used = 'a';
int dx[] = {-1,-1,-1,0,1,1, 1, 0};
int dy[] = {-1, 0, 1,1,1,0,-1,-1};
void floodFill(int ind,int x,int y)
{
    scope[ind][0] = x;
    int up = x, down = x, lf = y, rt = y;
    queue<Pair> que;
    que.push(make_pair(x,y));
    vis[x][y] = 1;
    while(!que.empty())
    {
        Pair tmp = que.front();que.pop();
        g[tmp.first][tmp.second] = '*';
        down = max(down,tmp.first);
        lf = min(lf,tmp.second);
        rt = max(rt,tmp.second);
        for(int i = 0;i<8;++i)
        {
            int nx = tmp.first + dx[i], ny = tmp.second + dy[i];
            if( nx>= 0 && nx <H && ny >=0 && ny <L)
                if(g[nx][ny] == '1' && vis[nx][ny] == 0) {vis[nx][ny] = 1;que.push(make_pair(nx,ny));}
        }
    }
    scope[ind][1] = down,scope[ind][2] = lf,scope[ind][3] = rt;
    
    int num = 0;
    string m = "";
    for(int i  = up;i<=down;++i)
        for(int j = lf;j<=rt;++j)
        {
            if(g[i][j] == '*') {m += "1";++num;}
            else m += "0";
        }
    state[ind] = m;snum[ind] = num;
}

void draw(int x)
{
    if(x == 1)
    {
        for(int i = scope[1][0];i<=scope[1][1];++i)
            for(int j = scope[1][2];j<=scope[1][3];++j)
                if(g[i][j] == '*') g[i][j] = 'a';
        mark[1] = 'a';
        return;
    }
    bool flag = false;
    int up = scope[x][0], down = scope[x][1], lf = scope[x][2], rt = scope[x][3];
    int upd = scope[x][1] - scope[x][0],lfr = scope[x][3] - scope[x][2];
    for(int i = 1;i<x;++i)
    {
        if(snum[i] != snum[x])continue;
        int xi = scope[i][1] - scope[i][0], yi = scope[i][3] - scope[i][2];
        if((upd == xi && lfr == yi) || (upd == yi && lfr == xi))
        {
            string s1 = "",s2 = "",s3 ="",s4 ="",s5 ="",s6 ="",s7 ="",s8 ="";
            for(int k = up;k<=down;++k)
                for(int j = lf;j<= rt;++j)
                {
                    if(g[k][j] == '*') s1 += "1";
                    else s1 += "0";
                }
            for(int j = lf;j<=rt;++j)
                for(int k = down;k>=up;--k)
                {
                    if(g[k][j] == '*') s2 += "1";
                    else s2 += "0";
                }
            for(int k = down;k>=up;--k)
                for(int j = rt;j>=lf;--j)
                {
                    if(g[k][j] == '*') s3 += "1";
                    else s3 += "0";
                }
            for(int j = rt;j>=lf;--j)
                for(int k = up;k<=down;++k)
                {
                    if(g[k][j] == '*') s4 += "1";
                    else s4 += "0";
                }
            for(int k = up;k<=down;++k)
                for(int j = rt;j>=lf;--j)
                {
                    if(g[k][j] == '*') s5 += "1";
                    else s5 += "0";
                }
            for(int j = lf;j<=rt;++j)
                for(int k = up;k<=down;++k)
                {
                    if(g[k][j] == '*') s6 += "1";
                    else s6 += "0";
                }
            for(int k = down;k>=up;--k)
                for(int j = lf;j<=rt;++j)
                {
                    if(g[k][j] == '*') s7 += "1";
                    else s7 += "0";
                }
            for(int j = rt;j>=lf;--j)
                for(int k = down;k>=up;--k)
                {
                    if(g[k][j] == '*') s8 += "1";
                    else s8 += "0";
                }
            if(s1 == state[i] || s2 == state[i] || s3 == state[i] || s4 == state[i] || s5 == state[i] || s6 == state[i] || s7 == state[i] || s8 == state[i])
            {
                flag = true;
                for(int k = up;k<=down;++k)
                    for(int j = lf;j<=rt;++j)
                        if(g[k][j] == '*') g[k][j] = mark[i];
                mark[x] = mark[i];
                break;
            }
        }
    }
    if(!flag)
    {
        used = used + 1;
        for(int i = up;i<=down;++i)
            for(int j = lf;j<=rt;++j)
                if(g[i][j] == '*') g[i][j] = used;
        mark[x] = used;
    }
}
int main()
{
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);
    cin >> L >> H;
    for(int i = 0;i<H;++i)
        for(int j = 0;j<L;++j) cin >> g[i][j];
    
    for(int i = 0;i<H;++i)
        for(int j = 0;j<L;++j)
        {
            if(g[i][j] == '0')continue;
            else if(vis[i][j] == 1) continue;
            ++curr;
            floodFill(curr, i, j);
            draw(curr);
        }
    for(int i = 0;i<H;++i){
        for(int j = 0;j<L;++j) cout << g[i][j];
        cout << endl;
    }
    return 0;
}
//  Created on 16/5/6.
/*
 23
 15
 10001000000000010000000
 01111100011111000101101
 01000000010001000111111
 00000000010101000101111
 00000111010001000000000
 00001001011111000000000
 10000001000000000000000
 00101000000111110010000
 00001000000100010011111
 00000001110101010100010
 00000100110100010000000
 00010001110111110000000
 00100001110000000100000
 00001000100001000100101
 00000001110001000111000
 */
