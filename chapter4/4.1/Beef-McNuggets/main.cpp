/*
 ID: miyunlu1
 PROG: nuggets
 LANG: C++11
 */
#include <iostream>
using namespace std;
int N;
int arry[11];
bool dp[65536];
int gcd(int a,int b)
{
    while(b)
    {
        b = a^b;
        a = a^b;
        b = (a^b)%a;
    }
    return a;
}

void quickSort(int s[],int l,int r)
{
    if(l < r)
    {
        int i = l,j = r,x = s[l];
        while(i < j)
        {
            while(i<j && s[j] >= x)--j;
            if(i < j) s[i++] = s[j];
            while(i<j && s[i] < x)++i;
            if(i < j) s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i-1);
        quickSort(s, i+1, r);
    }
}
int main()
{
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
    {
        cin >> arry[i];
        if(arry[i] == 1){cout << 0 << endl;return 0;}//1 exist
    }
    if(N == 1){cout << 0 << endl;return 0;}// a num and isn't 1
    quickSort(arry, 0, N-1);
    int g = arry[0];
    for(int i =1;i<N;++i) g = gcd(g, arry[i]);
    if(g != 1){cout << 0<<endl;return 0;}//gcd isn't 1
    
    int thre = arry[N-1] * arry[N-2] / gcd(arry[N-1], arry[N-2]);//no more than it
    dp[0] = true;
    for(int i = 1;i<= thre;++i)
        for(int j = 0;j<N && arry[j]<= i;++j)
            if(dp[i-arry[j]]){dp[i] = true;break;}
    
    for(int i = thre;i>=0;--i)if(!dp[i]){cout << i << endl;break;}
    return 0;
}
/*
 3
 3
 6
 10
 */







