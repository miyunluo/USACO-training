/*
 ID: miyunlu1
 PROG: pprime
 LANG: C++11
 */

#include <iostream>
using namespace std;

long list[1000000];
long tot = 0;
long A,B;

void make_palindrome()
{
    long a,b,c,d;
    
    for (d = 1; d <= 9; d += 2)
    {
        list[tot] = d;
        tot++;
    }
    
    for (d = 1; d <= 9; d+=2)
    {
        list[tot] = d * 11;
        tot++;
    }
    
    for (c = 1; c <= 9; c+=2)
        for (d = 0; d <= 9; d++)
        {
            list[tot] = c * 101 + d * 10;
            tot++;
        }
    
    for (c = 1; c <= 9; c+=2)
        for (d = 0; d <= 9; d++)
        {
            list[tot] = c * 1001 + d * 110;
            tot++;
        }
    
    for (b = 1; b <= 9; b+=2)
        for (c = 0; c <= 9; c++)
            for (d = 0; d <= 9; d++)
            {
                list[tot] = b * 10001 + c * 1010 + d * 100;
                tot++;
            }
    
    for (b = 1; b <= 9; b+=2)
        for (c = 0; c <= 9; c++)
            for (d = 0; d <= 9; d++)
            {
                list[tot] = b * 100001 + c * 10010 + d * 1100;
                tot++;
            }
    
    for (a = 1; a <= 9; a+=2)
        for (b = 0; b <= 9; b++)
            for (c = 0; c <= 9; c++)
                for (d = 0; d <= 9; d++)
                {
                    list[tot] = a * 1000001 + b * 100010 + c * 10100 + d * 1000;
                    tot++;
                }
    
    for (a = 1; a <= 9; a+=2)
        for (b = 0; b <= 9; b++)
            for (c = 0; c <= 9; c++)
                for (d = 0; d <= 9; d++)
                {
                    list[tot] = a * 10000001 + b * 1000010 + c * 100100 + d * 11000;
                    tot++;
                }
    return;
}
bool isplan(long x)
{
    if(x == 1 || x == 2) return true;
    
    for(long i = 2;i*i<=x;++i)
    {
        if(x%i == 0) return false;
    }
    return true;
}
void display()
{
    for(long i = 0;i<tot;++i)
        if(list[i]>=A && list[i]<=B && isplan(list[i])) cout<< list[i] <<endl;
}
int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out", "w", stdout);
    cin >> A >> B;
    make_palindrome();
    display();
    return 0;
}
