/*
 ID: miyunlu1
 PROG: prefix
 LANG: C++11
 */
#include <iostream>
//#include <string>
#include <cstring>
#include <stack>
//#include <algorithm>
using namespace std;

char sett[202][11];
int n = -1;
unsigned long size[202];
char line[200002];
int vis[200001];
stack<unsigned long> stk;
unsigned long best;

void init()
{
    do{
        cin >> sett[++n];
        size[n] = strlen(sett[n]);
    }while(sett[n][0] != '.');
    
    char a[80];
    while(cin >> a) strncat(line, a, sizeof(a)/sizeof(char));
}

void solution()
{
    stk.push(0);
    vis[0] = 1;
    while(!stk.empty())
    {
        unsigned long from = stk.top(); stk.pop();
        best = (best > from) ? best : from;
        for(int i =0;i<n;++i)
            if(strncmp(line+from, sett[i], size[i]) == 0 && !(vis[from + size[i]]++))
                stk.push(from+size[i]);
    }
    cout << best <<endl;
}
int main()
{
    //freopen("prefix.in", "r", stdin);
    //freopen("prefix.out", "w", stdout);
    init();
    solution();
    return 0;
}