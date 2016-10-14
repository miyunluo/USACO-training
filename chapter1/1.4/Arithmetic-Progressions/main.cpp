/*
 ID: miyunlu1
 PROG: ariprog
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
using namespace std;

int arry[200000] = {0};
struct ari{
    int head;
    int q;
};
ari ans[200000];
int arindx = 0;

bool cmp(const ari& a,const ari& b)
{
    if(a.q != b.q) return a.q < b.q;
    else return a.head < b.head;
}


int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    int length,border;
    cin >> length >> border;
    int aindex = 0;
    for(int i=0;i<=border;++i)
        for(int j=i;j<=border;++j)
        {
            aindex = i*i + j*j;
            arry[aindex] = 1;
        }
    
    int cha = (border*border + border*border) / (length - 1);
    
    int i,j,k;
    for(i = 0;i<70000;++i)
    {
        if(arry[i] == 1)
        {
            for(j = 1;j<=cha;++j)
            {
                bool flag = true;
                for(k = 1;k<length;++k)
                {
                    if(arry[i+j*k] == 0){flag = false;break;}
                }
                if(flag)
                {ans[arindx].head = i;ans[arindx].q = j;++arindx;}
            }
        }
    }
    
    sort(ans,ans+arindx,cmp);
    
    for(i = 0;i<arindx;++i)
    {
        cout << ans[i].head << ' ' <<ans[i].q <<endl;
    }
    
    if(arindx == 0) cout <<"NONE"<<endl;
    return 0;
}
/*
 1217 84
 2434 168
 4868 336
 6085 420
 9736 672
 10953 756
 12170 840
 12953 924
 15821 1092
*/