/*
 ID: miyunlu1
 PROG: tour
 LANG: C++11
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define INF 0x7fffffff
int N,L;
int g[101][101];
int f[101][101];
map<string, int> s;
int main()
{
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    cin >> N >> L;
    for(int i =1;i<=N;++i)
    {
        string tmp;
        cin >> tmp;
        s[tmp] = i;
    }
    for(int i =0;i<L;++i)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int d1 = s[s1],d2 = s[s2];
        g[d1][d2] = g[d2][d1] = 1;
    }
    
    f[1][1] = 1;
    for(int i = 1;i<=N;++i)
        for(int j = i+1;j<=N;++j){
            for(int k = 1;k<j;++k)
                if(g[k][j] && f[i][k] >0) f[i][j] = max(f[i][j],f[i][k] +1);
            f[j][i] = f[i][j];
        }
    int ans = 1;
    for(int i =1;i<=N;++i)
        if(g[i][N]) ans = max(ans,f[i][N]);
    cout << ans <<endl;
    return 0;
}
/*
 8 9
 Vancouver
 Yellowknife
 Edmonton
 Calgary
 Winnipeg
 Toronto
 Montreal
 Halifax
 Vancouver Edmonton
 Vancouver Calgary
 Calgary Winnipeg
 Winnipeg Toronto
 Toronto Halifax
 Montreal Halifax
 Edmonton Montreal
 Edmonton Yellowknife
 Edmonton Calgary
 */