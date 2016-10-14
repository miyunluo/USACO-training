/*
 ID: miyunlu1
 PROG: frameup
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pair;
int H,L,N;
bool present[26],vis[26];
char g[30][30];
Pair location[26][2];
vector<string> ans,anss;
string s ;
void DFS(int n,string curr)
{
    if(n == N){ans.push_back(curr);return;}
    for(int i = 0;i<26;++i)
    {
        if(present[i] == 0)continue;
        int x1 = location[i][0].first,y1 = location[i][0].second;
        int x2 = location[i][0].first,y2 = location[i][1].second;
        int x3 = location[i][1].first,y3 = location[i][0].second;
        int x4 = location[i][1].first,y4 = location[i][1].second;
        
        int left,right;
        for(int j = y1;j<L;++j)if(g[x1][j] == 'A'+i)right = j;
        for(int j = y4;j>=0;--j)if(g[x4][j] == 'A'+i)left = j;
        bool f1,f2,f3,f4;
        f1 = f2 = true;f3 = f4 = false;
        for(int j = left;j<=right;++j)
        {
            if(g[x1][j] == '.'){f1 = false;break;}
            if(g[x1][j] == ('A' + i) || vis[g[x1][j] - 'A'])continue;
            else {f1 = false;break;}
        }
        for(int j = left;j<=right;++j)
        {
            if(g[x3][j] == '.'){f2 = false;break;}
            if(g[x3][j] == ('A' + i) || vis[g[x3][j] - 'A'])continue;
            else {f2 = false;break;}
        }
        if(!f1 || !f2) continue;
        else{
            for(int j = right;j<L;++j)
            {
                bool p1 = false;
                if(g[x2][j] != ('A' + i) && !vis[g[x2][j] - 'A'])break;
                if(g[x4][j] != ('A' + i) && !vis[g[x4][j] - 'A'])break;
                if(g[x2][j] == ('A' + i) || g[x4][j] == ('A' + i)) p1 = true;
                bool flag = true;
                for(int k = x2+1;k<x4;++k)
                {
                    if(g[k][j] == '.'){flag = false;break;}
                    if(g[k][j] == ('A'+i)) p1 = true;
                    if(g[k][j] == ('A'+i) || vis[g[k][j] - 'A'])continue;
                    else {flag = false;break;}
                }
                if(flag && p1){f4 = true;break;}
            }
            for(int j = left;j>=0;--j)
            {
                bool p2 = false;
                if(g[x1][j] != ('A' + i) && !vis[g[x1][j] - 'A'])break;
                if(g[x3][j] != ('A' + i) && !vis[g[x3][j] - 'A'])break;
                if(g[x1][j] == ('A' + i) || g[x3][j] == ('A' + i)) p2 = true;
                bool flag = true;
                for(int k = x1+1;k<x3;++k)
                {
                    if(g[k][j] == '.'){flag = false;break;}
                    if(g[k][j] == ('A'+i)) p2 = true;
                    if(g[k][j] == ('A'+i) || vis[g[k][j] - 'A'])continue;
                    else {flag = false;break;}
                }
                if(flag && p2){f3 = true;break;}
            }
            
            if(f1 && f2 && f3 && f4)
            {
                present[i] = 0;vis[i] = 1;
                string str = curr;
                str += ('A' + i);
                DFS(n+1,str);
                present[i] = 1;vis[i] = 0;
            }
        }
    }
}
int main()
{
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    //freopen("/Users/miyunluo/Desktop/1.in", "r", stdin);
    //freopen("/Users/miyunluo/Desktop/1.out", "w", stdout);
    cin >> H >> L;
    for(int i =0;i<H;++i)
        for(int j = 0;j<L;++j)
        {
            cin >> g[i][j];
            if(g[i][j] != '.')
            {
                if(present[g[i][j] - 'A'] == 0)
                {
                    present[g[i][j] - 'A'] = 1;
                    ++N;
                    location[g[i][j] - 'A'][0] = make_pair(i,j);
                }
                else location[g[i][j] - 'A'][1] = make_pair(i,j);
            }
        }
    //string str = "";
    DFS(0,s);
    for(auto i = 0;i<ans.size();++i)
    {
        reverse(ans[i].begin(),ans[i].end());
        anss.push_back(ans[i]);
    }
    sort(anss.begin(),anss.end());
    for(auto i = 0;i<anss.size();++i) cout<< anss[i] << endl;
    return 0;
}
//  Created on 16/5/4.
/*
 6 9
 AAABBBCCC
 AQAQQQCQC
 AAABBBCCC
 XQXYYYZQZ
 XQQYQYQQZ
 XXXYYYZZZ
 */
