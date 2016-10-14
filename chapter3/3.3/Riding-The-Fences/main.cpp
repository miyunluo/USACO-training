/*
 ID: miyunlu1
 PROG: fence
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
struct edge{
    int t1,t2;
    int vis;
    inline int another(int t)
    {return ((t == t1)?t2:t1);}
    edge(){t1 = 0;t2 = 0;vis = 0;}
};
edge elist[1025];//保存所有边
int N;
int degree[501] = {0};//度数
int linjie[501][1024];//存放边的编号
int lindex[501] = {0};
vector<int> ans;

void quickSort(int p,int s[],int l,int r)
{
    if(l < r)
    {
        int i = l,j = r,x = s[l];
        while(i < j)
        {
            while(i < j && elist[s[j]].another(p) >= elist[x].another(p))
                j--;
            if(i < j)s[i++] = s[j];
            while(i < j && elist[s[i]].another(p) < elist[x].another(p))
                i++;
            if(i < j)s[j--] = s[i];
        }
        s[i] = x;
        quickSort(p, s, l, i-1);
        quickSort(p, s, i+1, r);
    }
}

void DFS(int start)
{
    for(int i = 0;i< lindex[start];++i)
    {
        edge &e = elist[linjie[start][i]];
        if(e.vis == 1)continue;
        e.vis = 1;
        DFS(e.another(start));
    }
    ans.push_back(start);
}
int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> N;
    int maxnum = 0 ,minnum = 600;
    for(int i = 1;i<=N;++i)
    {
        int a,b;
        cin >> a >> b;
        maxnum = max(maxnum,max(a,b));
        minnum = min(minnum,min(a,b));
        elist[i].t1 = a;elist[i].t2 = b;elist[i].vis = 0;
        linjie[a][lindex[a]++] = i;
        linjie[b][lindex[b]++] = i;
        ++degree[a];++degree[b];
    }
    
    /*
    for(int i = 1;i<=7;++i){
        cout << "i: "<<i <<' '<<"index: "<<lindex[i] << endl;
        for(int j = 0;j<lindex[i];++j) cout << linjie[i][j]<<' ';
        cout << endl;
    }*/
    //cout << endl;
    //cout <<"aaaaa"<< elist[1].another(1)<<endl;
    for(int i = minnum;i<=maxnum;++i)
        quickSort(i, linjie[i], 0, lindex[i]-1);
    /*
    for(int i = 1;i<=7;++i){
        cout << "i: "<<i <<' '<<"index: "<<lindex[i] << endl;
        for(int j = 0;j<lindex[i];++j) cout << linjie[i][j]<<' ';
        cout << endl;
    }*/
    
    int start = 501;
    for(int i = minnum;i<=maxnum;++i)
        if(degree[i] & 1) start = min(start,i);
    if(start == 501)
    {
        int s;
        for(s = minnum;s<=maxnum;++s)if(degree[s] != 0)break;
        start = s;
    }
    
    DFS(start);
    for(auto a = ans.rbegin();a!= ans.rend();++a) cout << *a << endl;
    return 0;
}
/*
 9
 1 2
 2 3
 3 4
 4 2
 4 5
 2 5
 5 6
 5 7
 4 6
 
 9
 1 2
 2 3
 3 4
 4 2
 4 5
 2 5
 5 6
 5 7
 4 6
 
 1
 2
 3
 4
 2
 5
 4
 6
 5
 7
 */
