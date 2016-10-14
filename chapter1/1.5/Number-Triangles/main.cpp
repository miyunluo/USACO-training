/*
 ID: miyunlu1
 PROG: numtri
 LANG: C++11
 */
#include <iostream>
using namespace std;

int arry[1001][1001];
int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int row;
    cin >> row;
    for(int i = 1;i<=row;++i)
        for(int j = 1;j<=i;++j) cin >> arry[i][j];
    
    for(int i = row - 1;i > 0;--i)
        for(int j = 1;j <= i;++j)
        {
            arry[i][j] += max(arry[i+1][j],arry[i+1][j+1]);
        }
    cout << arry[1][1]<<endl;
    return 0;
}