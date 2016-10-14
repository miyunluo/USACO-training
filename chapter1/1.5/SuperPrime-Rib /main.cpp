/*
 ID: miyunlu1
 PROG: sprime
 LANG: C++11
 */
#include <iostream>
using namespace std;
int N;
long list[9][100000] = {0};
int lindex[9] = {0};
bool isplan(long x)
{
    if(x == 2) return true;
    for(long i=2;i*i<=x;++i)
        if(x%i == 0)return false;
    return true;
}
void solutiona()
{
    int i,j;
    long num;
    for(i = 2;i<10;++i) if(isplan(i))list[1][lindex[1]++] = i;
    for(j = 0;j<lindex[1];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[1][j]*10 + i;
            if(isplan(num)) list[2][lindex[2]++] = num;
        }
    for(j = 0;j<lindex[2];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[2][j]*10 + i;
            if(isplan(num)) list[3][lindex[3]++] = num;
        }
    for(j = 0;j<lindex[3];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[3][j]*10 + i;
            if(isplan(num)) list[4][lindex[4]++] = num;
        }
    for(j = 0;j<lindex[4];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[4][j]*10 + i;
            if(isplan(num)) list[5][lindex[5]++] = num;
        }
    for(j = 0;j<lindex[5];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[5][j]*10 + i;
            if(isplan(num)) list[6][lindex[6]++] = num;
        }
    for(j = 0;j<lindex[6];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[6][j]*10 + i;
            if(isplan(num)) list[7][lindex[7]++] = num;
        }
    for(j = 0;j<lindex[7];++j)
        for(i = 1;i<10;i+=2)
        {
            num = list[7][j]*10 + i;
            if(isplan(num)) list[8][lindex[8]++] = num;
        }
}
void display()
{
    for(int i = 0;i<lindex[N];++i) cout << list[N][i]<<endl;
}
int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> N;
    solutiona();
    display();
    return 0;
}
