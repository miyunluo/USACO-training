/*
 ID: miyunlu1
 PROG: sort3
 LANG: C++11
 */
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int count[4],a[4],t[1001],x,n,k=0;
    memset(count,0,sizeof(count));
    memset(a,0,sizeof(a));
    fin>>n;
    while (fin>>x) {
        count[x]++;
        t[++k]=x;
    }
    for (int i=1;i<=count[1]+count[2];i++){
        if (t[i]==3) a[3]++;
        else if (t[i]==2&&i<=count[1]) a[1]++;
        else if (t[i]==1&&i>count[1]) a[2]++;
    }
    fout<<a[3]+(a[1]>a[2]?a[1]:a[2])<<endl;
}