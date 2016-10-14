/*
 ID: miyunlu1
 PROG: skidesign
 LANG: C++11
 */
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    
    int n,height;
    int num[101]={0};
    cin >> n;
    for(int i=0;i<n;++i){cin >> height;++num[height];}
    
    int start,end;
    for(start = 0;start<=100;++start){if(num[start] != 0)break;}
    for(end = 100;end>=0;--end){if(num[end] != 0)break;}
    
    //for(int i=0;i<=100;++i)cout <<i<<' '<<num[i]<<endl;
    //cout <<"start: "<<start <<"end: "<<end<<endl;
    
    int mincost = 99999999999;
    for(int i=start;i<=end-17;++i)
    {
        int frontcost = 0,behandcost = 0;
        for(int j=start;j<i;++j)
        {
            if(num[j])
                frontcost += (i-j)*(i-j)*num[j];
        }
        for(int k=end;k>i+17;--k)
        {
            if(num[k])
                behandcost += (k-i-17)*(k-i-17)*num[k];
        }
        mincost = min(mincost,(frontcost+behandcost));
    }
    cout << mincost<<endl;
    return 0;
}
/*
 50
 50
 84
 22
 44
 38
 0
 46
 66
 22
 73
 25
 92
 5
 56
 13
 73
 48
 32
 42
 91
 3
 100
 97
 8
 27
 34
 73
 58
 42
 80
 53
 59
 55
 52
 3
 30
 84
 100
 31
 80
 79
 11
 70
 55
 64
 92
 29
 77
 71
 72
 */
