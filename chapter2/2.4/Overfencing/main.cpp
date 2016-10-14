/*
 ID: miyunlu1
 PROG: maze1
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

int ans;

struct node{
    int x,y;
    int s;
    node(int a,int b,int c){x = a;y = b;s = c;}
};

int H,W;
int maze[202][80];//保存迷宫的数据
//bool vis[202][80];//记录是否访问

int X[] = {0,-1,0,1};//一个点的4个方向
int Y[] = {-1,0,1,0};
queue<node*> que;

void init()
{
    cin.get();
    string linein;
    for(int i =0;i<H;++i)
    {
        getline(cin,linein);
        //cout << "sample" << linein << ' '<< linein.size()<<endl;
        for(int j = 0;j<W && j<linein.size();++j)
        {
            if(linein[j] != ' ')maze[i][j] = 1;
        }
    }
    /*
     for(int i =0;i<H;++i)
     for(int j = 0;j<W;++j)
     {
     cout << maze[i][j]<<' ';
     if(j == W-1)cout <<endl;
     }
     */
}

void BFS()
{
    while(!que.empty())
    {
        node*tmp = que.front();que.pop();
        if(maze[tmp->x + X[0]][tmp->y + Y[0]] != 1)//可以走
        {
            if((tmp->y + Y[0])!= 0 && maze[tmp->x+X[0]*2][tmp->y+Y[0]*2] == 0)//如果该方向下一个点没访问就走
            {
                maze[tmp->x+X[0]*2][tmp->y+Y[0]*2] = tmp->s+1;
                node*p = new node(tmp->x+X[0]*2,tmp->y+Y[0]*2,tmp->s+1);
                que.push(p);
            }
        }
        if(maze[tmp->x + X[1]][tmp->y + Y[1]] != 1)//可以走
        {
            if((tmp->x + X[1]) != 0 && maze[tmp->x+X[1]*2][tmp->y+Y[1]*2] == 0)
            {
                maze[tmp->x+X[1]*2][tmp->y+Y[1]*2] = tmp->s+1;
                node*p = new node(tmp->x+X[1]*2,tmp->y+Y[1]*2,tmp->s+1);
                que.push(p);
            }
        }
        if(maze[tmp->x + X[2]][tmp->y + Y[2]] != 1)//可以走
        {
            if((tmp->y + Y[2]) != W-1 && maze[tmp->x+X[2]*2][tmp->y+Y[2]*2] == 0)
            {
                maze[tmp->x+X[2]*2][tmp->y+Y[2]*2] = tmp->s+1;
                node*p = new node(tmp->x+X[2]*2,tmp->y+Y[2]*2,tmp->s+1);
                que.push(p);
            }
        }
        if(maze[tmp->x + X[3]][tmp->y + Y[3]] != 1)//可以走
        {
            if((tmp->x + X[3]) != H-1 && maze[tmp->x+X[3]*2][tmp->y+Y[3]*2] == 0)
            {
                maze[tmp->x+X[3]*2][tmp->y+Y[3]*2] = tmp->s+1;
                node*p = new node(tmp->x+X[3]*2,tmp->y+Y[3]*2,tmp->s+1);
                que.push(p);
            }
        }
    }
}
void findans()
{
    int maxx = 0;
    for(int i =0;i<H;++i)
        for(int j = 0;j<W;++j)
            maxx = max(maxx,maze[i][j]);
    cout << maxx <<endl;
}
void findStartAndGo()
{
    for(int i = 0;i<W;++i)
    {
        if(maze[0][i] == 0)
        {
            maze[1][i] = 1;
            node* p = new node(1,i,1);
            que.push(p);
        }
    }
    for(int i = 0;i<W;++i)
    {
        if(maze[H-1][i] == 0)
        {
            maze[H-2][i] = 1;
            node*p = new node(H-2,i,1);
            que.push(p);
        }
    }
    for(int i = 0;i<H;++i)
    {
        if(maze[i][0] == 0)
        {
            maze[i][1] = 1;
            node*p = new node(i,1,1);
            que.push(p);
        }
    }
    for(int i = 0;i<H;++i)
    {
        if(maze[i][W-1] == 0)
        {
            maze[i][W-2] = 1;
            node*p = new node(i,W-2,1);
            que.push(p);
        }
    }
}
int main()
{
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    cin >> W >> H;
    H = H*2+1;
    W = W*2+1;
    //cout << "w: "<<W<<' '<<"h:"<<H<<endl;
    init();
    findStartAndGo();
    BFS();
    findans();
}
/*
5 3
+-+-+-+-+-+
|         |
+-+ +-+ + +
|     | | |
+ +-+-+ + +
| |     |
+-+ +-+-+-+
 

 
 */
