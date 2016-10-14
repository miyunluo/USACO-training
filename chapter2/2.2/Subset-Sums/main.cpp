/*
 ID: miyunlu1
 PROG: subset
 LANG: C++11
 */

//真tm巧妙啊啊啊啊啊啊啊啊啊啊啊啊!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;
unsigned long ans[40][400];

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int N;
    cin >> N;
    int MAX = (1+N)*N/2;
    if(MAX%2 != 0){cout << 0 <<endl;return 0;}
    MAX /= 2;
    ans[1][0] = 1;
    ans[1][1] = 1;
    for(int i = 2;i<=N;++i)
        for(int j = 0;j<=MAX;++j)
        {
            if((j-i) >= 0)ans[i][j] = ans[i-1][j] + ans[i-1][j-i];
            else ans[i][j] = ans[i-1][j];
        }
    cout << (ans[N][MAX]/2) << endl;
    return 0;
}
