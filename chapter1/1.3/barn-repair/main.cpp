/*
 ID: miyunlu1
 PROG: barn1
 LANG: C++11
 */
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

/*
int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    
    int woodnum,roomnum,cownum;
    scanf("%d",&woodnum);scanf("%d",&roomnum);scanf("%d",&cownum);
    
    int a[201];
    int i,j;
    for(i=0;i<cownum;++i) {scanf("%d",&a[i]);}
    sort(a,a+cownum);
    int b[201];
    for(i=0;i<cownum-1;++i){b[i] = a[i+1]-a[i]-1;}
    
    int minlen = a[cownum-1] - a[0] + 1;
    
    for(i=1;i<woodnum;++i)
    {
        int maxblank = 0,tmp = 201;
        for(j=0;j<cownum-1;++j) if(b[j]>maxblank) {maxblank = b[j];tmp = j;}
        b[tmp] = 0;
        minlen -= maxblank;
    }
    
    
    printf("%d\n",minlen);
    return 0;
}
*/


int a[200], b[200];

int main()                           //写的太漂亮了
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int m, s, c;
    scanf("%d%d%d", &m, &s, &c);
    for (int i = 0; i < c; ++i)
        scanf("%d", &a[i]);
    sort(a, a+c);                   //升序排列
    s = a[c-1]-a[0]+1;
    for (int i = 1; i < c; ++i)
        b[i] = a[i]-a[i-1]-1;
    sort(b+1, b+c, greater<int>()); //降序排列
    for (int i = 1; i < m; ++i)
        s -= b[i];
    printf("%d\n", s);
}
