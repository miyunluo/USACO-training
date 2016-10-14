/*
 ID: miyunlu1
 PROG: lamps
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int C,N;
string result(101,'2');
vector<string> ans;

void solution(int step,string s)
{
    if(step == (C+1))
    {
        bool flag = true;
        for(int i = 0;i<N;++i)
        {
            if(result[i] == '2') continue;
            else
                if(result[i] != s[i]){flag = false;break;}
        }
        if(flag) ans.push_back(s);
        return;
    }
    
    for(int i = 0;i<4;++i)
    {
        string ss = s;
        if(i == 0)
        {
            for(int j = 0;j<N;++j){ss[j] = 1 - (ss[j]-'0') + '0';}
            solution(step +1, ss);
        }
        if(i == 1)
        {
            for(int j = 1;j<N;j += 2){ss[j] = 1 - (ss[j]-'0') + '0';}
            solution(step +1, ss);
        }
        if(i == 2)
        {
            for(int j = 0;j<N;j += 2){ss[j] = 1 - (ss[j]-'0') + '0';}
            solution(step +1, ss);
        }
        if(i == 3)
        {
            for(int j = 0;(3*j+1)<=N;++j){ss[3*j] = 1 - (ss[3*j]-'0') + '0';}
            solution(step +1, ss);
        }
    }
}

void display()
{
    sort(ans.begin(),ans.end());
    vector<string>::iterator lf = ans.begin(),rt = ans.end();
    if(lf == rt) {cout <<"IMPOSSIBLE"<<endl;return;}
    string tmp(N,'2');
    while(lf != rt)
    {
        if(tmp != *lf){cout << *lf <<endl;tmp = *lf;}
        ++lf;
    }
}

int main()
{
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> N >> C;
    /******************************************************************/
    while(C > 4)C -= 2; //我擦，就这一句，是多么强大的剪枝啊!!!!!!!!!!!!!!!!!!
    //我擦嘞，每个按键，按两次相当于没按!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /******************************************************************/
    int a;
    while(cin >> a && a!= -1) result[a-1] = '1';
    while(cin >> a && a!= -1) result[a-1] = '0';
    string lamp(N,'1');
    solution(1, lamp);
    display();
    return 0;
}
/*
 0000000000
 0101010101
 0110110110
*/