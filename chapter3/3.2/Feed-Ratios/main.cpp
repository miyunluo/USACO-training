/*
 ID: miyunlu1
 PROG: ratios
 LANG: C++11
 */
#include <iostream>
using namespace std;
int aim[3];
int repl[3][3];
int aimnum = 1000;
int num1 = 10000,num2 = 10000,num3 = 10000;
int main()
{
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    for(int i = 0;i<3;++i)cin >> aim[i];
    
    for(int i = 0;i<3;++i)
        for(int j = 0;j<3;++j)
            cin >> repl[i][j];
    
    for(int i = 1;i<=100;++i)
        for(int j = 0;j<=100;++j)
            for(int k = 0;k<=100;++k)
                for(int q = 0;q<=100;++q)
                {
                    int ant0,ant1,ant2;
                    ant0 = j*repl[0][0] +k*repl[1][0]+ q*repl[2][0];
                    ant1 = j*repl[0][1] +k*repl[1][1]+ q*repl[2][1];
                    ant2 = j*repl[0][2] +k*repl[1][2]+ q*repl[2][2];
                    {
                        if(ant0 == i*aim[0] && ant1 == i*aim[1] && ant2 == i*aim[2])
                            if((j+k+q) < (num1+num2+num3))
                            {num1 = j;num2 = k;num3 = q;aimnum = i;}
                    }
                }
    if(aimnum == 1000)cout <<"NONE"<<endl;
    else cout << num1 <<' '<<num2<<' '<<num3<<' '<<aimnum<<endl;
    return 0;
}

