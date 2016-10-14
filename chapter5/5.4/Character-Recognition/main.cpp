/*
 ID: miyunlu1
 PROG: charrec
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <climits>
using namespace std;

string letter = " abcdefghijklmnopqrstuvwxyz";
char font[28][21][21], given[1201][21], ans[101];
int ansl[1201][4], difference[28][21][1201], cost[1201][4];
int dp[1201][2];
int main()
{
    int n;
    
    freopen("font.in", "r", stdin);
    cin >> n;
    for(int i = 1;i<=27;++i)
        for(int j = 1;j<=20;++j)
            for(int k = 1;k<=20;++k) cin >> font[i][j][k];
    freopen("charrec.in", "r", stdin);
    freopen("charrec.out", "w", stdout);
    cin >> n;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=20;++j) cin >> given[i][j];
    
    for(int i = 1;i<=27;++i)
        for(int j = 1;j<=20;++j)
            for(int k = 1;k<=n;++k)
                for(int l = 1;l<=20;++l)
                    difference[i][j][k] += int(font[i][j][l] != given[k][l]);
    
    int p,tmp = 0;
    for(int i = 1; i <= n; i++){
        cost[i][1] = cost[i][2] = cost[i][3] = INT_MAX;
        for(int j = 1; j <= 27; j++){       //枚举字符
            if(i + 18 <= n){        //少一行
                for(p = 2, tmp = 0; p <= 20; p++) tmp += difference[j][p][i + p - 2];
                if(tmp < cost[i][1]) cost[i][1] = tmp, ansl[i][1] = j;
                for(p = 2; p <= 20; p++){
                    tmp += difference[j][p - 1][i + p - 2], tmp -= difference[j][p][i + p - 2];
                    if(tmp < cost[i][1]) cost[i][1] = tmp, ansl[i][1] = j;
                }
            }
            if(i + 19 <= n){
                for(p = 1, tmp = 0; p <= 20; p++) tmp += difference[j][p][i + p - 1];
                if(tmp < cost[i][2]) cost[i][2] = tmp, ansl[i][2] = j;
            }
            if(i + 20 <= n){
                for(p = 2, tmp = difference[j][1][i]; p <= 20; p++) tmp += difference[j][p][i + p];
                if(tmp < cost[i][3]) cost[i][3] = tmp, ansl[i][3] = j;
                for(p = 2; p <= 20; p++){
                    tmp += difference[j][p][i + p - 1], tmp -= difference[j][p][i + p];
                    if(tmp < cost[i][3]) cost[i][3] = tmp, ansl[i][3] = j;
                }
            }
        }
    }

    for (dp[0][0] = 0, p = 1; p <= n; p++) dp[p][0] = INT_MAX;
    for(int i = 19; i <= n; i++){
        if(i - 19 >= 0 && dp[i - 19][0] < INT_MAX && dp[i - 19][0] + cost[i - 18][1] < dp[i][0])
            dp[i][0] = dp[i - 19][0] + cost[i - 18][1], dp[i][1] = 19;
        if(i - 20 >= 0 && dp[i - 20][0] < INT_MAX && dp[i - 20][0] + cost[i - 19][2] < dp[i][0])
            dp[i][0] = dp[i - 20][0] + cost[i - 19][2], dp[i][1] = 20;
        if(i - 21 >= 0 && dp[i - 21][0] < INT_MAX && dp[i - 21][0] + cost[i - 20][3] < dp[i][0])
            dp[i][0] = dp[i - 21][0] + cost[i - 20][3], dp[i][1] = 21;
    }
    
    //for(int i = 1;i<=n;++i)cout << dp[i][1] << ' ';
    for(p = n, tmp = 0; p; p -= dp[p][1])
        ans[++tmp] = ansl[p - dp[p][1] + 1][dp[p][1] - 18];
    for(int i = tmp; i >= 1; i--)
        cout << letter[ans[i] - 1];
    cout << endl;
}
//  Created on 16/5/25.
//  Rewrite on 16/9/14.