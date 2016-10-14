/*
 ID: miyunlu1
 PROG: combo
 LANG: C++11
 */
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int n;
bool close(int a, int b)
{
    if (abs(a-b) <= 2) return true;
    if (abs(a-b) >= n - 2) return true;
    return false;
}

bool close_enough(int n1, int n2, int n3,
                  int c1, int c2, int c3)
{
    return close(n1,c1) && close(n2,c2) && close(n3,c3);
}

int a[3],b[3];
int main()
{
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    
    int i,j,k,amont = 0;
    cin >> n >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=1;k<=n;++k)
                if( close_enough(i,j,k,a[0],a[1],a[2])||close_enough(i,j,k,b[0],b[1],b[2]) )
                {++ amont;}
    cout << amont<<endl;
    
    
    return 0;
}