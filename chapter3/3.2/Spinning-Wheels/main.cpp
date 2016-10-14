/*
 ID: miyunlu1
 PROG: spin
 LANG: C++11
 */
#include <iostream>
#include <cstring>
using namespace std;
bool spin[5][360];
int speed[5];
int cracknum[5];
int crackhead[5][5];
int cracklen[5][5];
int main()
{
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    for(int i = 0;i<5;++i)
    {
        cin >> speed[i];
        cin >> cracknum[i];
        for(int j = 0;j<cracknum[i];++j) cin >> crackhead[i][j] >> cracklen[i][j];
    }
    //times 为0的情况
    memset(spin,0,sizeof(spin));
    for(int i = 0;i<5;++i)
        for(int j = 0;j<cracknum[i];++j)
        {
            for(int k = crackhead[i][j];k<=crackhead[i][j] + cracklen[i][j];++k)
                spin[i][k % 360] = 1;
        }
    for(int p = 0;p<360;++p)
    {
        if(spin[0][p] == 1 && spin[1][p] == 1 && spin[2][p] == 1 && spin[3][p] == 1 && spin[4][p] == 1)
        {cout << 0 << endl;return 0;}
    }
    //times从1开始循环
    int times = 1;
    for(;;)
    {
        memset(spin,0,sizeof(spin));
        for(int i = 0;i<5;++i)
            for(int j = 0;j<cracknum[i];++j)
            {
                crackhead[i][j] = (crackhead[i][j] + speed[i]) % 360;
                for(int k = crackhead[i][j];k<=crackhead[i][j] + cracklen[i][j];++k)
                    spin[i][k % 360] = 1;
            }
        bool flag = false;
        for(int p = 0;p<360;++p)
        {
            if(spin[0][p] == 1 && spin[1][p] == 1 && spin[2][p] == 1 && spin[3][p] == 1 && spin[4][p] == 1)
            {cout << times << endl;flag = true;break;}
        }
        ++times;
        if(flag)break;
        if(times >360){cout << "none"<<endl;break;}
    }
    return 0;
}
