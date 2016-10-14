/*
 ID: miyunlu1
 PROG: hidden
 LANG: C++11
 */
#include <iostream>
using namespace std;
char str[200005];
int L;
int main()
{
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    cin  >> L;
    for(int i = 0;i<L;++i)
    {
        cin >> str[i];
        str[L + i] = str[i];
    }
    int i =0,j = 1,k;
    while(j<L)
    {
        for(k = 0;k<L;++k)
            if(str[i+k] != str[j+k]) break;
        if(str[i+k] == str[j+k]) break; //整个字符串相等
        if(str[i+k] < str[j+k]) j = j+k+1;
        else i = j,++j;
    }
    cout << i << endl;
    return 0;
}