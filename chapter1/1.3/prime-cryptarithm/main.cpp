/*
 ID: miyunlu1
 PROG: crypt1
 LANG: C++11
 */
#include<iostream>   //lingrenyanqianyiliangaaaaaaaa
#include<fstream>
using namespace std;
#define jud(t) for(int x=t;x;x/=10) if( (1<<(x%10)|k) != k ) flag=false;
int main()
{
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");
    int n,t,k=0,cnt=0;
    cin >> n;
    while(n--)
    {
        cin>>t;
        k|=1<<t;
        //cout << "k:" << bitset<32>(k) << endl;
    }
    for(int i=100;i<1000;i++)
        for(int j=10;j<100&&i*j<10000;j++)
        {
            if(i*(j/10)>999||i*(j%10)>999) continue;
            bool flag=true;
            jud(i);jud(j);jud(i*j);jud(i*(j/10));jud(i*(j%10));
            cnt += flag;
        }
    cout<<cnt<<endl;
    return 0;
}

