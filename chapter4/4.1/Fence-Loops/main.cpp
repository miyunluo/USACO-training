/*
 ID: miyunlu1
 PROG: fence6
 LANG: C++11
 */
#include<iostream>
using namespace std;
int inf = 999999;
int N;
int NP;
int edgeLen[101];//lenth of each edge
int edgeNum[101][2];//edge num
int edgeFind[101][2][101];
int edgeId[101][2][9];
int point[2][201];//
int table[201][201];
int dis[201][201];

void findP()
{
    for(int i=1;i<=N;++i)
    {
        if(point[0][i] == 0)
        {
            point[0][i] = ++NP;
            for(int j =1;j<=edgeNum[i][0];++j)
            {
                int e = edgeId[i][0][j];
                if(edgeFind[e][0][i] == 1) {point[0][e] = point[0][i];}
                if(edgeFind[e][1][i] == 1) {point[1][e] = point[0][i];}
            }
        }
        
        if(point[1][i] == 0)
        {
            point[1][i] = ++NP;
            for(int j =1;j<=edgeNum[i][1];++j)
            {
                int e = edgeId[i][1][j];
                if(edgeFind[e][0][i] == 1) {point[0][e] = point[1][i];}
                if(edgeFind[e][1][i] == 1) {point[1][e] = point[1][i];}
            }
        }
        
        table[point[0][i]][point[1][i]] = edgeLen[i];
        table[point[1][i]][point[0][i]] = edgeLen[i];
    }
    //cout << "NP: "<<NP<<endl;
}
void floyd()
{
    int ans = inf;
    for(int k=1;k<=NP;++k)
    {
        for(int i =1;i<k;++k)
            for(int j=i+1;j<k;++j)
            {
                int tmp = dis[i][j]+table[i][k]+table[k][j];
                if(tmp < ans)ans = tmp;
            }
        for(int i=1;i<=NP;++i)
            for(int j =1;j<=NP;++j)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    cout << ans <<endl;
}
//谁tm能告诉我，这上下两个函数有啥区别，为啥上面的不行，下面的可以!!!!!!!!!!!!!!!
void Floyd()
{
    int ans=inf;
    for(int k=1;k<=NP;k++)
    {
        for(int i=1;i<k;i++)
            for(int j=i+1;j<k;j++)
                if(dis[i][j]+table[i][k]+table[k][j]<ans)
                {ans=dis[i][j]+table[i][k]+table[k][j];}
        
        for(int i=1;i<=NP;i++)
            for(int j=1;j<=NP;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    }
    cout << ans<<endl;
}

int main()
{
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    cin >> N;
    for(int i = 0;i<N;++i)
    {
        int id,len,num0,num1,e;
        cin >> id >> len >> num0 >> num1;
        edgeLen[id] = len;
        edgeNum[id][0] = num0;
        edgeNum[id][1] = num1;
        for(int j=1;j<=num0;++j)
        {
            cin >> e;
            edgeId[id][0][j] = e;
            edgeFind[id][0][e] = 1;
        }
        for(int j=1;j<=num1;++j)
        {
            cin >> e;
            edgeId[id][1][j] = e;
            edgeFind[id][1][e] = 1;
        }
    }
    
    for(int i = 0;i<=200;++i)
        for(int j = 0;j<=200;++j){table[i][j] = inf;}
    findP();
    /*
    for(int i = 1;i<=7;++i){
        for(int j =1;j<=7;++j)cout << table[i][j]<<' ';
        cout <<endl;
    }*/
    for(int i = 0;i<=200;++i)
        for(int j = 0;j<=200;++j){dis[i][j] = table[i][j];}
    Floyd();
    return 0;
}
/*
 10
 1 16 2 2
 2 7
 10 6
 2 3 2 2
 1 7
 8 3
 3 3 2 1
 8 2
 4
 4 8 1 3
 3
 9 10 5
 5 8 3 1
 9 10 4
 6
 6 6 1 2
 5
 1 10
 7 5 2 2
 1 2
 8 9
 8 4 2 2
 2 3
 7 9
 9 5 2 3
 7 8
 4 5 10
 10 10 2 3
 1 6
 4 9 5
*/