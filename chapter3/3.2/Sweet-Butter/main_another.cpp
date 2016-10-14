/*
 ID: miyunlu1
 PROG: butter
 LANG: C++11
 */
#include <iostream>
#include <cstring>
using namespace std;
int N,P,C; //奶牛500 牧场800 道路1450
int cowIn[501];
int road[801][801];
int step[501];

void Floyd()
{
    for(int k = 1;k<=P;++k)//
        for(int i = 1;i<=P;++i)
            for(int j = 1;j<=P;++j)
            {
                    if(road[i][j] > (road[i][k] + road[k][j]))
                        road[i][j] = road[i][k] + road[k][j];
            }
}
void findRoad()
{
    for(int i = 1;i<=P;++i)
    {
        int num = 0;
        for(int j = 1;j<=N;++j)
            num += road[cowIn[j]][i];
        //cout << "num: "<<num <<endl;
        step[i] = num;
    }
}
void display()
{
    int ans = 999999999;
    //for(int i = 1;i<=P;++i) cout << step[i]<<' ';
    //cout << endl;
    for(int i = 1;i<=P;++i) ans = min(ans,step[i]);
    cout << ans <<endl;
}
int main()
{
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    cin >> N >> P >> C;
    for(int i =1;i<=N;++i) cin >> cowIn[i];
    
    int inf = 9999999;
    for(int i = 0;i<=800;++i)
        for(int j = 0;j<=800;++j) road[i][j] = inf;
    
    for(int i = 1;i<=P;++i) road[i][i] = 0;
    
    for(int i = 0;i<C;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if( a != b)
        {
            if(road[a][b] == inf)road[a][b] = road[b][a] = c;
            else {
                int p = min(c,road[a][b]);
                road[a][b] = road[b][a] = p;
            }
        }
    }
    Floyd();
    
    /*
    for(int i = 1;i<=P;++i){
        for(int j = 1;j<=P;++j)cout << road[i][j]<<' ';
        cout << endl;
    }*/
    
    findRoad();
    display();
    return 0;
}
/*
 3 4 5
 2
 3
 4
 1 2 1
 1 3 5
 2 3 7
 2 4 3
 3 4 5
 */
