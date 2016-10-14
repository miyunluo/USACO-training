/*
 ID: miyunlu1
 PROG: shuttle
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x7ffffff
string str, aim;
vector<string> ans;
unsigned long minStep = INF;
void DFS(int B_ind,string s,string path)
{
    if(s == aim)
    {
        if(path.size() < minStep)
        {
            minStep = path.size();
            ans.clear();
            ans.push_back(path);
        }
        else if(path.size() == minStep) ans.push_back(path);
        return;
    }
    
    int numOf_left_B = 0,numOf_right_W = 0;
    for(int i = B_ind-1;i>=0;--i) //WBB
    {
        if(s[i] == 'W')
        {
            if(numOf_left_B >=2)return;
            else {
                numOf_left_B = 0;
                continue;
            }
        }
        else numOf_left_B +=1;
    }
    
    for(int i = B_ind+1;i<s.size();++i) //WWB
    {
        if(s[i] == 'B')
        {
            if(numOf_right_W >=2)return;
            else {
                numOf_right_W = 0;
                continue;
            }
        }
        else numOf_right_W += 1;
    }
    
    if(B_ind-1 >=0 && s[B_ind-1] == 'W')
    {
        string tmp = s,p = path;
        tmp[B_ind] = tmp[B_ind-1];
        tmp[B_ind-1] = ' ';
        p += '0' + B_ind -1;
        DFS(B_ind-1, tmp, p);
    }
    if(B_ind+1 <s.size() && s[B_ind+1] == 'B')
    {
        string tmp = s,p = path;
        tmp[B_ind] = tmp[B_ind+1];
        tmp[B_ind+1] = ' ';
        p += '0' + B_ind +1;
        DFS(B_ind+1, tmp, p);
    }
    if(B_ind-2 >=0)
    {
        string tmp = s,p = path;
        if(tmp[B_ind-2] != tmp[B_ind-1] && tmp[B_ind -2] == 'W')
        {
            tmp[B_ind] = tmp[B_ind-2];
            tmp[B_ind-2] = ' ';
            p += '0' + B_ind -2;
            DFS(B_ind-2, tmp, p);
        }
    }
    if(B_ind+2 < s.size())
    {
        string tmp = s,p = path;
        if(tmp[B_ind+2] != tmp[B_ind+1] && tmp[B_ind+2] == 'B')
        {
            tmp[B_ind] = tmp[B_ind+2];
            tmp[B_ind+2] = ' ';
            p += '0' + B_ind +2;
            DFS(B_ind+2, tmp, p);
        }
    }
}
int main()
{
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0;i<num;++i){str += "W";aim += "B";}
    str += " ";aim += " ";
    for(int i = 0;i<num;++i){str += "B";aim += "W";}
    string path = "";
    DFS(num, str, path);
    sort(ans.begin(),ans.end());
    int cnt = 0;
    cout << ans[0][0]-'0' +1;
    ++cnt;
    for(auto i = 1;i<ans[0].size();++i)
    {
        if(cnt == 0)cout <<ans[0][i] - '0'+1;
        else cout << ' '<<ans[0][i] - '0'+1;
        ++cnt;
        if(cnt == 20){cout << endl;cnt = 0;}
    }
    if(cnt != 0)cout << endl;
    return 0;
}
//  Created on 16/4/30.

