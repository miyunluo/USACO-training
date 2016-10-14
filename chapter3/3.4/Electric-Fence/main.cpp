/*
 ID: miyunlu1
 PROG: fence9
 LANG: C++11
 */
#include <iostream>
#include <cmath>
using namespace std;
int m,n,p;
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
int main()
{
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    cin >> m >> n >> p;
    
    int edgeNode = gcd(m, n) + p + gcd(abs(m-p), n);
    int S = p * n /2;
    int insideNode = S - edgeNode/2 + 1;
    
    cout << insideNode << endl;
    return 0;
}