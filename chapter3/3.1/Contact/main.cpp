/*
 ID: miyunlu1
 PROG: contact
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int A,B,N;
int present[8200][13];
int main()
{
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    cin >> A >> B >> N;
    string str,tmp;
    while(cin >> tmp) str += tmp;
    int strlen = str.length();
    for(int len = A;len <= B;++len)
        for(int j = 0;j+len-1<strlen;++j)
        {
            bitset<16> tmp = 0;
            for(int k = 0;k<len;++k) tmp[k] = str[j+len-1-k]-'0';
            ++present[tmp.to_ulong()][len];
        }
    /*
    for(int i = 0;i<8200;++i){
        for(int j = 1;j<13;++j)
            cout << present[i][j]<<' ';
        cout << endl;}
    */
    int num = 0;
    while(num != N)
    {
        int maxx = -1;
        int x = 0,y = 0;
        for(int j = 1;j<13;++j)
            for(int i = 0;i<8200;++i){
                if(present[i][j] > maxx) {maxx = present[i][j];x = i;y = j;}
                if(present[i][j] == maxx){x = i;y = j;}
            }
        if(maxx == 0)break;
        else{cout << maxx << endl;++num;}
        //cout << "x: "<<x<<' '<<"y: "<<y<<endl;
        int times = 0;
        for(int j = 1;j<13;++j)
            for(int i = 0;i<8200;++i)
            {
                if(present[i][j] == maxx)
                {
                    present[i][j] = 0;
                    if(i!=x || j!=y)
                    {
                        bitset<16> p = i;
                        for(int k = j-1;k>=0;--k)cout <<p[k];
                        ++times;
                        if(times == 6){times = 0;cout <<endl;}
                        else cout <<' ';
                    }
                    if(i == x && j==y)
                    {
                        bitset<16> p = i;
                        for(int k = j-1;k>=0;--k)cout <<p[k];
                        cout <<endl;
                    }
                }
            }
    }
    return 0;
}
/*
 23
 00
 15
 01 10
 12
 100
 11
 11 000 001
 10
 010
 8
 0100
 7
 0010 1001
 6
 111 0000
 5
 011 110 1000
 4
 0001 0011 1100

*/