/*
 ID: miyunlu1
 PROG: comehome
 LANG: C++11
 */
#include <iostream>
#include <queue>
using namespace std;
int N;
int table[52][52];//存储距离
int dis[52];//最短路径
bool inque[52] = {false};
int main()
{
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
    {
        char a,b;
        int c;
        cin >> a >> b >> c;
        int x,y;
        if(int(a) > 64 && int(a) < 91)x = a - 'A';//大写存在0到25
        else x = a - 'a' + 26;
        if(int(b) > 64 && int(b) < 91)y = b - 'A';
        else y = b - 'a' + 26;
        //草，这里要判断重边啊!!!!!!!!!!!!
        if(table[x][y] == 0)table[x][y] = table[y][x] = c;
        else {table[x][y] = table[y][x] = min(table[x][y],c);}
    }
    //for(int i = 0;i<52;++i) table[i][i] = 0;
    for(int i = 0;i<52;++i) dis[i] = 999999999;
    dis[25] = 0;
    queue<int> que;
    que.push(25);
    inque[25] = true;
    while(!que.empty())
    {
        int node = que.front();que.pop();
        inque[node] = false;
        for(int i =0;i<52;++i)
        {
            if(i != node)
            {
                if(table[node][i] != 0 && (dis[i] > dis[node] + table[node][i]))
                {
                    dis[i] = dis[node] + table[node][i];
                    if(!inque[i]){que.push(i);inque[i] = true;}
                }
            }
        }
    }
    
    int dymin = 999999999,midex = 0;
    char ans;
    //for(int i = 0;i<25;++i) cout << dis[i] <<' ';
    //cout << endl;
    for(int i = 0;i<25;++i)
    {
        if(dymin > dis[i]){dymin = dis[i];midex = i;}
    }
    ans = 'A' + midex;
    cout << ans <<' '<<dymin<<endl;
    return 0;
}