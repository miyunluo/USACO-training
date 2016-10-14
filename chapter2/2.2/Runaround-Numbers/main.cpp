/*
 ID: miyunlu1
 PROG: runround
 LANG: C++11
 */
#include <iostream>
#include <string>
using namespace std;
unsigned long M;

bool judge(unsigned long x)
{
    string tmp = to_string(x);
    if(tmp.find('0') != string::npos)return false;//除去0
    
    string::size_type len = tmp.size();
    for(int i = 0;i<len;++i)
        for(int j = 0;j<len;++j)//除重
        {
            if(i == j)continue;
            if(tmp[i] == tmp[j]) return false;
        }

    bool *vis = new bool[len];
    for(int i = 0;i < len;++i)vis[i] = false;
    
    unsigned long sindex = (tmp[0]-'0')%len,times = 0;
    while(!vis[sindex])
    {
        vis[sindex] = true;
        ++times;
        sindex = (sindex+(tmp[sindex] - '0'))%len;
    }
    if(times == len)return true;
    else return false;
}

int main()
{
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    cin >> M;
    unsigned long i = M + 1;
    for(;;)
    {
        if(judge(i)) {cout << i <<endl;break;}
        else ++i;
    }
    return 0;
}