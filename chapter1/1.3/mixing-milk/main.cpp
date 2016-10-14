/*
 ID: miyunlu1
 PROG: milk
 LANG: C++11
 */
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;


struct farm
{
    int price;
    int num;
};

bool cmp(farm a,farm b)
{
    if(a.price != b.price)return a.price < b.price;
    else return a.num > b.num;
}

int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    
    int total,peop,minmy = 0;
    scanf("%d",&total);
    scanf("%d",&peop);
    
    farm a[5001];
    int i;
    for(i = 0;i<peop;++i){scanf("%d",&a[i].price);scanf("%d",&a[i].num);}
    
    sort(a,a+peop,cmp);
    
    for(i=0;i<peop;++i)
    {
        if(total > a[i].num){minmy += a[i].price * a[i].num;total -= a[i].num;}
        else {minmy += total * a[i].price;break;}
    }
    
    printf("%d\n",minmy);
    return 0;
}