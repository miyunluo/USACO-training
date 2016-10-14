/*
 ID: miyunlu1
 PROG: inflate
 LANG: C++11
 */
//666真是妙不可言，将二维简化为一维
#include <iostream>
using namespace std;
int cap,N;
int weight[10001];
int cost[10001];
int dp[10001];
void completeBag(int ccost,int wweight)
{
    if(ccost <= cap)
    {
        for(int v = ccost;v <= cap;++v)
            dp[v] = max(dp[v],(dp[v-ccost] + wweight));
    }
}
int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    cin >> cap >> N;
    for(int i = 1;i<=N;++i) {cin >> weight[i] >> cost[i];}
    for(int i = 1;i<=N;++i) completeBag(cost[i], weight[i]);
    cout << dp[cap] <<endl;
    return 0;
}