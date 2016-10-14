/*
 ID: miyunlu1
 PROG: range
 LANG: C++11
 */
#include <iostream>
#include <string>
using namespace std;
int N;
int ans[251];
int llist[250][250];
int init[251][251];
int minHeng[250][250];
struct node{
    int h,z;
    node(){h = z = 0;}
};
node v[251][251];

void solution()
{
    for(int i = N-1;i>=0;--i){//the first line
        if(llist[0][i] == 0) {v[0][i].h = 0;v[0][i].z = 0;minHeng[0][i] = 0;}
        else {
            init[0][i] += init[0][i+1];
            v[0][i].h = init[0][i];
            v[0][i].z = 1;
            minHeng[0][i] = v[0][i].h;
        }
    }
    for(int i = 1;i<N;++i)
    {
        for(int j = N-1;j>=0;--j)
        {
            if(llist[i][j] == 0){v[i][j].h = 0;v[i][j].z = 0;minHeng[i][j] = 0;}
            else {
                init[i][j] += init[i][j+1];
                v[i][j].h = init[i][j];
                v[i][j].z = 1;
                minHeng[i][j] = v[i][j].h;
                for(int k = i-1;k>=0;--k)
                    if(llist[k][j] == 0)break;
                    else v[k][j].z += 1;
            }
        }
        for(int a = 0;a<i;++a)
            for(int b = 0;b<N-1;++b)
            {
                if(llist[a][b] == 0)continue;
                int zong = v[a][b].z;
                int heng = v[i][b].h;
                heng = min(heng,minHeng[a][b]);
                minHeng[a][b] = heng;
                int square = min(heng,zong);
                if(square == i-a+1) ++ans[square];
            }
    }
}
int main()
{
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    cin >> N;
    string str;
    for(int i = 0;i<N;++i)
    {
        cin >> str;
        for(int j = 0;j<N;++j)llist[i][j] = init[i][j] = str[j]-'0';
    }
    solution();
    for(int i = 2;i<=N;++i)
        if(ans[i] != 0) cout << i<<' '<<ans[i]<<endl;
    return 0;
            
}
/*
 25
 1100100001100111110001011
 1001101111011001000011000
 1011101101000111001100010
 1110110000000000010100010
 0101000000110001010000001
 1110001011001001011001000
 0100011010101110000100011
 1000011000000011100100011
 0011011100001010010010111
 1111110010010100010011011
 0111110101011011010000011
 1100110010001010001101011
 1110111001010000000111100
 1010000011101001101111011
 1010000010110101000010100
 0010001101000110011101100
 0001000100011110110100110
 1111111111011111111010101
 0001100110111001010101101
 1011000101010010001010001
 1010111101001000010001111
 1010110101010010010011110
 0101010110011001001111001
 1100001000100101100000111
 0001111101010110110100110
*/