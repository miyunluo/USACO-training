/*
 ID: miyunlu1
 PROG: castle
 LANG: C++11
 */
#include <iostream>
using namespace std;
int row,col;
int **castle;//保存城堡的二维数组
int **mark;//标记方格是否被访问，同时将方格分组
int *roomcap;//纪录房间的大小
int roomnum = 1;//房间个数
int maxroom = 0;//砸墙后的最大容量
//墙的位置
int hang,lie;
char dir;
int aim[] = {2,4,3,5,6,10,12,7,11,13,14,15};//可能要砸墙的方格的值

void DFS(int x,int y)
{
    if(mark[x][y] != 0)return;
    
    mark[x][y] = roomnum;
    ++ roomcap[roomnum];
    switch(castle[x][y])
    {
        case 0://没墙
            if(x != 0) DFS(x-1,y); //向北
            if(y != col -1) DFS(x,y+1);//向东
            if(x != row -1) DFS(x+1,y);//向南
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 1: //西边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(y != col -1) DFS(x,y+1);//向东
            if(x != row -1) DFS(x+1,y);//向南
            break;
        case 2: //北边有墙
            if(y != 0) DFS(x,y-1);
            if(x != row -1) DFS(x+1,y);
            if(y != col -1) DFS(x,y+1);
            break;
        case 4:// 东边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(x != row -1) DFS(x+1,y);//向南
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 8:// 南边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(y != col -1) DFS(x,y+1);//向东
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 3:// 西边北边有墙
            if(y != col -1) DFS(x,y+1);//向东
            if(x != row -1) DFS(x+1,y);//向南
            break;
        case 5:// 西边东边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(x != row -1) DFS(x+1,y);//向南
            break;
        case 9:// 西边南边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(y != col -1) DFS(x,y+1);//向东
            break;
        case 6:// 北边东边有墙
            if(x != row -1) DFS(x+1,y);//向南
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 10:// 北边南边有墙
            if(y != col -1) DFS(x,y+1);//向东
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 12:// 东边南边有墙
            if(x != 0) DFS(x-1,y); //向北
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 7:// 西边 北边 东边有墙
            if(x != row -1) DFS(x+1,y);//向南
            break;
        case 11://西边 北边 南边有墙
            if(y != col -1) DFS(x,y+1);//向东
            break;
        case 13://西边 南边 东边
            if(x != 0) DFS(x-1,y); //向北
            break;
        case 14://北边 东边 南边
            if(y != 0) DFS(x,y-1);//向西
            break;
        case 15://全有
            break;
    }
}

void findroom()
{
    for(int i =0;i<row;++i)
        for(int j =0;j<col;++j)
        {
            if(mark[i][j] == 0) {DFS(i,j);++roomnum;}
        }
}

bool maybeAim(int x)
{
    for(int i = 0;i<12;++i)if(x == aim[i])return true;
    return false;
}
void findwall()
{
    for(int j = 0;j<col;++j)
        for(int i = row-1;i>=0;--i)
        {
            if(maybeAim(castle[i][j]))
            {
                //先北墙
                if(i != 0)
                {
                    if(mark[i-1][j] != mark[i][j])
                    {
                        int cap = roomcap[mark[i-1][j]] + roomcap[mark[i][j]];
                        if(cap > maxroom)
                        {maxroom = cap;hang = i;lie = j;dir = 'N';}
                    }
                }
                //后东墙
                if(j != col-1)
                {
                    if(mark[i][j] != mark[i][j+1])
                    {
                        int cap = roomcap[mark[i][j]] + roomcap[mark[i][j+1]];
                        if(cap > maxroom)
                        {maxroom = cap;hang = i;lie = j;dir = 'E';}
                    }
                }
            }
        }
}
int findmax()  //没砸墙前的最大房间的大小
{
    int m = roomcap[0];
    for(int i = 0;i<roomnum;++i) if(roomcap[i] > m) m = roomcap[i];
    return m;
}
int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    
    cin >> col >> row;
    
    int i,j;
    castle = new int*[row];
    for(i = 0;i<row;++i) castle[i] = new int[col];
    mark = new int*[row];
    for(i = 0;i<row;++i) mark[i] = new int[col];
    roomcap = new int[row*col];
    
    for(i = 0;i<row*col;++i) roomcap[i] = 0;
    for(i = 0;i<row;++i)
        for(j = 0;j<col;++j){cin >> castle[i][j];mark[i][j] = 0;}
    
    findroom();
    findwall();
    
    cout << (roomnum - 1)<<endl;
    cout << findmax()<<endl;
    cout << maxroom<<endl;
    cout << (hang+1) <<' '<<(lie+1) <<' '<<dir<<endl;
    /*
    for(i = 0;i<row;++i)
        for(j = 0;j<col;++j)
        {
            cout << mark[i][j]<<' ';
            if(j == col-1)cout <<endl;
        }
    for(i = 1;i<roomnum;++i)cout << i <<" : "<<roomcap[i]<<endl;
     */
    return 0;
}
/*
 5 5
 3 2 6 3 6
 1 8 4 1 4
 13 7 13 9 4
 3 0 2 6 5
 9 8 8 12 13
*/