/*
 ID: miyunlu1
 PROG: shopping
 LANG: C++11
 */
#include <iostream>
using namespace std;
int P;
int zuhe[100];
pair<int, int>youHui[100][5];
int yhPrice[100];

int Q;
int buylist[5][3];
int nyouhui[100][6];
int dp[6][6][6][6][6];

void buyListSort()
{
    bool flag = false;
    for(int i = 0;i<Q;++i){
        for(int j = 0;j<=Q-2;++j)
            if(buylist[j][0] > buylist[j+1][0])
            {
                flag = true;
                int a,b,c;
                a = buylist[j][0];
                b = buylist[j][1];
                c = buylist[j][2];
                buylist[j][0] = buylist[j+1][0];
                buylist[j][1] = buylist[j+1][1];
                buylist[j][2] = buylist[j+1][2];
                buylist[j+1][0] = a;
                buylist[j+1][1] = b;
                buylist[j+1][2] = c;
            }
        if(!flag)break;
    }
}
void buildYH()
{
    for(int i=0;i<P;++i){
        for(int j = 0;j<zuhe[i];++j)
        {
            int p = youHui[i][j].first;
            for(int k =0;k<5;++k)
                if(p == buylist[k][0]) {nyouhui[i][k] = youHui[i][j].second;break;}
        }
        nyouhui[i][5] = yhPrice[i];
    }
}
int main()
{
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    cin >> P;
    for(int i = 0;i<P;++i)
    {
        cin >> zuhe[i];
        for(int j = 0;j<zuhe[i];++j)
        {
            int a,b;
            cin >> a >> b;
            youHui[i][j].first = a;
            youHui[i][j].second = b;
        }
        cin >> yhPrice[i];
    }
    cin >> Q;
    for(int i = 0;i<Q;++i)cin >> buylist[i][0] >> buylist[i][1] >> buylist[i][2];
    
    buyListSort();//buylist按编号大小排序
    buildYH();//构建优惠列表 和bulist的编号对应，优惠价格放在[5]位置
    /*
    for(int i = 0;i<5;++i){
        for(int j = 0;j<3;++j) cout << buylist[i][j]<<' ';
        cout << endl;
    }
    
    for(int i = 0;i<3;++i){
        for(int j = 0;j<6;++j)cout << nyouhui[i][j] <<' ';
        cout << endl;
    }*/
    
    dp[0][0][0][0][0] = 0;
    for(int x1 = 0;x1 < 6;++x1)
        for(int x2 = 0;x2 < 6;++x2)
            for(int x3 = 0;x3 < 6;++x3)
                for(int x4 = 0;x4 < 6;++x4)
                    for(int x5 = 0;x5 < 6;++x5)
                    {
                        dp[x1][x2][x3][x4][x5] = x1 * buylist[0][2] + x2 * buylist[1][2] + x3 * buylist[2][2] + x4 * buylist[3][2] + x5 * buylist[4][2];
                        for(int i = 0;i<P;++i)
                        {
                            if(x1 - nyouhui[i][0] >=0 && x2 - nyouhui[i][1] >=0 && x3 - nyouhui[i][2] >=0 && x4 - nyouhui[i][3] >=0 && x5 - nyouhui[i][4] >=0)
                                dp[x1][x2][x3][x4][x5] = min(dp[x1][x2][x3][x4][x5],(dp[x1 - nyouhui[i][0]][x2 - nyouhui[i][1]][x3 - nyouhui[i][2]][x4 - nyouhui[i][3]][x5 - nyouhui[i][4]] + nyouhui[i][5]));
                        }
                    }
    cout << dp[buylist[0][1]][buylist[1][1]][buylist[2][1]][buylist[3][1]][buylist[4][1]] << endl;
}
/*
 2
 1 7 3 5
 2 7 1 8 2 10
 2
 7 3 2
 8 2 5
*/