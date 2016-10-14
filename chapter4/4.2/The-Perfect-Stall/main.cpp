/*
 ID: miyunlu1
 PROG: stall4
 LANG: C++11
 */
#include <iostream>
#include <cstring>
using namespace std;
bool line[201][201];
bool used[201];
int match[201];
int N,M;
int ans;
/*
void DFS(int step,int involved)
{
    if(step == N){ans = max(ans,involved);return;}
    int n = in[step][0];
    for(int i=1;i<=n;++i)
        if(!occupied[in[step][i]])
        {
            occupied[in[step][i]] = true;
            DFS(step+1, involved+1);
            occupied[in[step][i]] = false;
        }
    DFS(step+1, involved);// escape the current one
}
*/
bool findPath(int x)
{
    for(int j = 1;j<=M;++j)
        if(line[x][j] == true && used[j] == false)//如果不在增广路经上
        {
            used[j] = true;//加入路径
            if(match[j] == 0 || findPath(match[j]))
            {match[j] = x;return true;}
        }
    return false;
}
void hungary()
{
    for(int i = 1;i<=N;++i)
    {
        memset(used, 0, sizeof(used));
        if(findPath(i)) ++ans;
    }
}
int main()
{
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    cin >> N >> M;
    int num;
    for(int i=1;i<=N;++i)
    {
        cin >> num;
        for(int j =0;j<num;++j)
        {
            int p;
            cin >> p;
            line[i][p] = true;
        }
    }
    hungary();
    cout << ans <<endl;
    return 0;
}
