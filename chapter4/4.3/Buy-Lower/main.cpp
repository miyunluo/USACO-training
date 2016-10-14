/*
 ID: miyunlu1
 PROG: buylow
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int day;
long price[5000];
int maxL[5000];
int ind[5000];
string amount[5000];
int present[200000];

string ADD(string x1,string x2)
{
    string ans = "";
    auto minlen = x1.size() < x2.size()? x1.size(): x2.size();
    int carry = 0;
    int i;
    for(i =0;i<minlen;++i)
    {
        int tmp = (x1[i]-'0') + (x2[i]-'0') + carry;
        ans += tmp%10 + '0';
        carry = tmp / 10;
    }
    while(i < x1.size())
    {
        int tmp = (x1[i]-'0') + carry;
        ans += tmp%10 + '0';
        carry = tmp /10;
        ++i;
    }
    while(i < x2.size())
    {
        int tmp = (x2[i]-'0') + carry;
        ans += tmp%10 + '0';
        carry = tmp /10;
        ++i;
    }
    if(carry != 0) ans += "1";
    return ans;
}
int main()
{
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    cin >> day;
    for(int i =0;i<day;++i)cin >> price[i];
    for(int i = 0;i<day;++i) {maxL[i] = 1;amount[i] = "0";}
    memset(present, -1, sizeof(present));
    for(int i = 0;i<day;++i)
    {
        if(present[price[i]] == -1)present[price[i]] = i;
        else{ind[present[price[i]]] = i;present[price[i]] = i;}
    }
    //for(int i = 0;i<day;++i) cout << ind[i]<<' ';
    //cout <<endl<<endl;
    for(int i = 0;i<day;++i){
        int prev = 1,tmp;
        string zan = "1";
        for(int j = 0;j<i;++j){ 
            if(price[j] > price[i])
            {
                if(ind[j]!= 0 && ind[j]<i && maxL[j] <= maxL[ind[j]])continue;
                tmp = maxL[j] + 1;
                if(prev == 1)
                {
                    prev = tmp;
                    zan = amount[j];
                }
                else{
                    if(tmp == prev) zan = ADD(zan,amount[j]);
                    if(tmp > prev)
                    {prev = tmp;zan = amount[j];}
                }
            }  
        }
        maxL[i] = prev;
        amount[i] = zan;
    }
    
    int maxlen = 0;
    //for(int i = 0;i<day;++i)cout << maxL[i]<<' ';
    //cout <<endl<< endl;
    for(int i = 0;i<day;++i)if(maxL[i] > maxlen) maxlen = maxL[i];
    //cout << maxlen<<endl;
    //for(int i = 0;i<day;++i)cout << amount[i]<<' ';
    //cout<<endl << endl;
    string ans = "0";
    for(int i = 0;i<day;++i)
        if(maxL[i] == maxlen)
        {
            if(ind[i] != 0)continue;
            ans = ADD(ans,amount[i]);
        }
    reverse(ans.begin(),ans.end());
    cout << maxlen <<' ' <<ans << endl;
    return 0;
}


//  Created by miyunluo on 16/4/24.


/*
 12
 68 69 54 64 68 64 70 67
 78 62 98 87
 
 10
 1 2 3 4 5 6 7 8 9 10
 
 20
 1 16 17 18 20 10 22 22 8 17
 26 14 3 24 8 1 2 21 2 17
 */
