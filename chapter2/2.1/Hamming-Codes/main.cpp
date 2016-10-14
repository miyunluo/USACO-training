/*
 ID: miyunlu1
 PROG: hamming
 LANG: C++11
 */
#include <iostream>
#include <bitset>
using namespace std;
int N,B,D;
bitset<8> list[65] = {0};
int lindex = 1;

bool judge(bitset<8> &a,bitset<8> &b)
{
    bitset<8> c = a^b;
    int amount = 0;
    for(int i =0;i<8;++i)
        if(c[i] == 1)++amount;
    if(amount >= D)return true;
    else return false;
}
void solution()
{
    int num = 1;
    for(int i = 1;i<(1<<9);++i)
    {
        if(num == N)return;
        bitset<8> tmp = i;
        int j;
        for(j = 0;j<lindex;++j)
            if(!judge(tmp, list[j]))break;
        if(j == lindex)
        {list[lindex++] = tmp;++num;}
    }
}
void display()
{
    int count = 0;
    for(int i = 0;i<lindex-1;++i)
    {
        if(count == 9){cout << list[i].to_ulong() << endl;count = 0;}
        else{
            cout << list[i].to_ulong()<<' ';
            ++count;
        }
    }
    cout << list[lindex - 1].to_ulong()<<endl;
}
int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> N >> B >> D;
    solution();
    display();
    return 0;
}
/*
 0 7 25 30 42 45 51 52 75 76
 82 85 97 102 120 127
*/