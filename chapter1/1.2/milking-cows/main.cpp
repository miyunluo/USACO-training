/*
 ID: miyunlu1
 PROG: milk2
 LANG: C++11
 */
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


struct node
{
    int data;
    int flag;
};

bool cmp(node &n1,node &n2)
{
    if(n1.data == n2.data)return n1.flag < n2.flag;
    else return n1.data < n2.data;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    
    int n,i;
    node mtime[10001];
    scanf("%d",&n);
    for(i=1;i<=2*n;i=i+2)
    {
        scanf("%d",&mtime[i].data);
        mtime[i].flag = -1;
        scanf("%d",&mtime[i+1].data);
        mtime[i+1].flag = 1;
    }
    
    sort(mtime+1,mtime + 2*n + 1,cmp);
    
    int maxwork = 0,maxfree = 0,tmp1 = 0,tmp2 = 0,num = 0;
    
    int lftime = 1;
    for(i=1;i<=2*n;++i)
    {
        num += mtime[i].flag;
        
        if(num == 0)
        {
            tmp1 = mtime[i].data - mtime[lftime].data;
            tmp2 = mtime[i+1].data - mtime[i].data;
            lftime = i+1;
            
            maxwork = max(maxwork,tmp1);
            maxfree = max(maxfree,tmp2);
        }
    }
    
    printf("%d %d\n",maxwork,maxfree);
    
    return 0;
    
}



