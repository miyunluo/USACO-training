/*
 ID: miyunlu1
 PROG: game1
 LANG: C++11
 */
#include <iostream>
using namespace std;
int N;
int num[101];
int sum[101][101];
int dp[101][101];
int main()
{
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    cin >> N;
    for(int i = 1;i<=N;++i) {cin >> num[i];sum[i][i] = num[i];}
    
    for(int i = 1;i<=N;++i)
        for(int j = i+1;j<=N;++j)
            sum[i][j] = sum[i][j-1] + num[j];
    
    for(int i = 1;i<=N;++i) dp[i][i] = num[i];
    for(int len = 1;len <N;++len)
        for(int i = 1;i<= N-len;++i)
            dp[i][i+len] = sum[i][i+len] - min(dp[i+1][i+len],dp[i][i+len-1]);
    cout << dp[1][N]<<' '<<(sum[1][N] - dp[1][N])<<endl;
    return 0;
}