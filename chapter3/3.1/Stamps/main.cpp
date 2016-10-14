/*
 ID: miyunlu1
 PROG: stamps
 LANG: C++11
 */
//dp问题，dp[]保存最小张数，对于每个确定的钱数，小于他的最小问题已知，用stamps[]向过迁移
#include <iostream>
#include <algorithm>
using namespace std;
int K,N;
int stamps[51];
int dp[2000001];

int main()
{
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    cin >> K >> N;
    int maxstamp = 0;
    for(int i = 0;i < N;++i){cin >> stamps[i];maxstamp = max(maxstamp,stamps[i]);}
    sort(stamps,stamps + N);
    dp[0] = 0;
    for(int i = 1;i<= maxstamp*200;++i)
    {
        int minn = 201;
        for(int j = 0;j<N && i>=stamps[j];++j)
        {
            minn = min((dp[i-stamps[j]]+1),minn);
        }
        dp[i] = minn;
        if(dp[i] > K){cout << i-1 <<endl;break;}
    }
    return 0;
}