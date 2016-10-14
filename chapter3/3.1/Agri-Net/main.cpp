/*
 ID: miyunlu1
 PROG: agrinet
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
using namespace std;
class DisjointSet
{
private:
    int * parent;
    int size;
public:
    DisjointSet(int si)
    {
        size = si;
        parent = new int[size];
        for (int i = 0; i < size; i++)
            parent[i] = -1;
    }
    ~DisjointSet(){ delete[] parent; }
    int Find(int x)
    {
        if (parent[x] < 0)return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int root1, int root2)
    {
        if (root1 == root2)return;
        if (parent[root1] > parent[root2])
        {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else
        {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
    }
};

struct node{
    int duan1;
    int duan2;
    int weight;
};
bool cmp(const node& a,const node&b)
{return a.weight < b.weight;}

int N;
int table[100][100];
node edgelist[10000];
int edgeindex = 0;
DisjointSet ds(100);

int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
        for(int j = 0;j<N;++j) cin >> table[i][j];
    for(int i = 0;i<N;++i)
        for(int j = i+1;j<N;++j)
        {
            edgelist[edgeindex].duan1 = i;
            edgelist[edgeindex].duan2 = j;
            edgelist[edgeindex].weight = table[i][j];
            ++edgeindex;
        }
    sort(edgelist,edgelist+edgeindex,cmp);
    int minnet = 0;
    for(int i = 0;i<edgeindex;++i)
    {
        if(ds.Find(edgelist[i].duan1) != ds.Find(edgelist[i].duan2))
        {
            ds.Union(ds.Find(edgelist[i].duan1), ds.Find(edgelist[i].duan2));
            minnet += edgelist[i].weight;
        }
    }
    cout << minnet << endl;
    return 0;
}