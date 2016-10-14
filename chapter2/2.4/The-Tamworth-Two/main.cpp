/*
 ID: miyunlu1
 PROG: ttwo
 LANG: C++11
 */
#include <iostream>
using namespace std;
int mapp[10][10];
struct point{
    int line,col;
    int dir;
};
point farmer,cows;
//空地->0,障碍->1
//左->1,上->2,右->3,下->4
void solution()
{
    int cont = 0;
    for(;;)
    {
        if(cont >1000000){cout << 0 << endl;break;}
        switch(farmer.dir){
            case 1:
                if(farmer.col == 0 || mapp[farmer.line][farmer.col-1] == 1)
                    farmer.dir = 2;
                else farmer.col -= 1;
                break;
            case 2:
                if(farmer.line == 0 || mapp[farmer.line-1][farmer.col] == 1)
                    farmer.dir = 3;
                else farmer.line -= 1;
                break;
            case 3:
                if(farmer.col == 9 || mapp[farmer.line][farmer.col+1] == 1)
                    farmer.dir = 4;
                else farmer.col += 1;
                break;
            case 4:
                if(farmer.line == 9 || mapp[farmer.line+1][farmer.col] == 1)
                    farmer.dir = 1;
                else farmer.line += 1;
        }
        
        switch(cows.dir){
            case 1:
                if(cows.col == 0 || mapp[cows.line][cows.col-1] == 1)
                    cows.dir = 2;
                else cows.col -= 1;
                break;
            case 2:
                if(cows.line == 0 || mapp[cows.line-1][cows.col] == 1)
                    cows.dir = 3;
                else cows.line -= 1;
                break;
            case 3:
                if(cows.col == 9 || mapp[cows.line][cows.col+1] == 1)
                    cows.dir = 4;
                else cows.col += 1;
                break;
            case 4:
                if(cows.line == 9 || mapp[cows.line+1][cows.col] == 1)
                    cows.dir = 1;
                else cows.line += 1;
        }
        
        ++ cont;
        if(farmer.line == cows.line && farmer.col == cows.col)
        {cout << cont << endl;break;}
    }
}
int main()
{
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    for(int i = 0;i<10;++i)
        for(int j = 0;j<10;++j)
        {
            char q;
            cin >> q;
            if(q == '*')mapp[i][j] = 1;
            if(q == 'C'){cows.line = i;cows.col = j;cows.dir = 2;}
            if(q == 'F'){farmer.line = i;farmer.col = j;farmer.dir = 2;}
        }
    solution();
    return 0;
}