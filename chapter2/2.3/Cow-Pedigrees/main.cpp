/*
 ID: miyunlu1
 PROG: nocows
 LANG: C++11
 */
#include <iostream>
using namespace std;
int N,K;
int table[200][200];

int main()
{
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    cin >> N >> K;
    table[1][1] = 1;
    for(int node = 3;node <= N;node+=2)
        for(int lfnode = 1;lfnode<=node-2;lfnode+=2)
            for(int lfdp = 1;lfdp <= (lfnode+1)/2;++lfdp)
                for(int rtdp = 1;rtdp <= (node-lfnode)/2;++rtdp)
                {
                    table[node][max(lfdp,rtdp)+1] += table[lfnode][lfdp] * table[node - lfnode-1][rtdp];
                    table[node][max(lfdp,rtdp)+1] %= 9901;
                }
    cout << table[N][K]<<endl;
    return 0;
}
       