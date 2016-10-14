
/*
 ID: miyunlu1
 PROG: dualpal
 LANG: C++11
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int n,s;

bool flag = false;

bool pan(int x,int i)
{
    int a[100000];
    int xia = 0;
    while(x>0){a[++xia] = x%i; x /= i;}
    
    int t = xia;
    for(;(xia>0)&&a[xia] == a[t-xia+1];--xia);
    
    if(xia == 0) return true;
    else return false;
}


void handle(int x)
{
    int t = 0;
    int i;
    for(i=2;i<=10;++i)
    {
        if(t == 2) break;
        if(pan(x,i)) ++ t;
    }
    
    if(t == 2)flag = true;
    else flag = false;
}


int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out","w", stdout);
    
    scanf("%d",&n);
    scanf("%d",&s);
    
    int num = 0,curr = s;
    
    while(num<n)
    {
        flag = false;
        ++curr;
        handle(curr);
        if(flag){ cout<<curr<<'\n';++num;}
    }
    
    return 0;
}