/*
 ID: miyunlu1
 PROG: bigbrn
 LANG: C++11
 */
#include <iostream>
using namespace std;
bool tree[1001][1001];
int maxl[1001][1001];
int N,T;
int main()
{
    freopen("bigbrn.in","r",stdin);
	freopen("bigbrn.out","w",stdout);
    cin >> N >> T;
    for(int i = 1;i<=N;++i)
        for(int j = 1;j<=N;++j)maxl[i][j] = 1;
    for(int i = 0;i<T;++i)
    {
        int x,y;
        cin >> x >> y;
        tree[x][y] = true;maxl[x][y] = 0;
    }
    int maxx = 0;
    for(int i =N-1;i>=1;--i)
        for(int j=N-1;j>=1;--j)
            if(!tree[i][j])
            {
                maxl[i][j] = min(maxl[i+1][j],min(maxl[i+1][j+1],maxl[i][j+1])) + 1;
                maxx = max(maxx,maxl[i][j]);
            }
    cout << maxx <<endl;
    return 0;
}
/*
 8 3
 2 2
 2 6
 6 3
*/