/*
 ID: miyunlu1
 PROG: holstein
 LANG: C++11
 */
#include <iostream>
#include <bitset>
using namespace std;

int V;
int minimun[26];
int G;
int siliao[16][26];
bitset<16>MIN(0);

void solution()
{
    size_t vary = 16;
    for(int i = 0;i<(1<<G);++i)
    {
        int v[26] = {0};
        bitset<16>bit(i);
        for(int a=0;a!=G;++a)
            if(bit[a])
                for(int b = 0;b != V;++b)
                    v[b] += siliao[a][b];
        bool flag = true;
        for(int j = 0;j<V;++j)
            if(v[j]<minimun[j]){flag = false;break;}
        if(flag && bit.count()< vary && bit.to_ulong()>MIN.to_ulong())
        {vary = bit.count();MIN = bit;}
    }
    
    cout << vary;
    for(int i=0;i!=G;i++)
        if(MIN[i])cout << ' ' <<i+1 ;
    cout << endl;
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> V;
    for(int i = 0;i<V;++i) cin >> minimun[i];
    cin >> G;
    for(int i = 0;i<G;++i)
        for(int j = 0;j<V;++j) cin >> siliao[i][j];
    solution();
    return 0;
}
