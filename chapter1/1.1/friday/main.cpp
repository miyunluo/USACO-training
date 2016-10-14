/*
 ID: miyunlu1
 PROG: friday
 LANG: C++11
 */
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int monthday[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ,
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapyear(int y)
{
    if(y % 400==0) return 1;
    else if((y%4==0) && (y%100)) return 1;
    else return 0;
}

int num[8] = {0};

int main()
{
    freopen("friday.in","r", stdin);
    freopen("friday.out", "w", stdout);
    
    int n,i,j,tmp1 = 0,tmp2;
    scanf("%d",&n);
    
    for(i=0;i<n;++i)
    {
        for(j=1;j<=12;++j)
        {
            tmp1 += monthday[leapyear(1900 +i)][j-1];
            tmp2 = tmp1 + 12;
            ++num[tmp2%7 + 1];
        }
        tmp1 += monthday[leapyear(1900 +i)][12];
    }
    
    printf("%d %d ",num[6],num[7]);
    printf("%d %d %d %d %d\n",num[1],num[2],num[3],num[4],num[5]);
    
    return 0;
}