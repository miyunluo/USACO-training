/*
 ID: miyunlu1
 PROG: sort3
 LANG: C++11
 */
#include <iostream>
using namespace std;

int list[1001];
int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int total1 = 0,total2 = 0,total3 = 0;
    int N;
    int exchange = 0;
    cin >> N;
    for(int i =0;i<N;++i)
    {
        cin >> list[i];
        switch(list[i])
        {
            case 1:++total1;break;
            case 2:++total2;break;
            case 3:++total3;break;
        }
    }
    int i,j;
    
    for(i = N-1;i>=(total1+total2);--i)
    {
        if(list[i] != 3)
        {
            if(list[i] == 1)
            {
                for(j = 0;j<total1;++j)
                    if(list[j] == 3)break;
                if(j == total1)
                    for(j = total1;j<total1+total2;++j)
                        if(list[j] == 3)break;
                list[j] = list[i];
                list[i] = 3;
                ++exchange;
            }
            if(list[i] == 2)
            {
                for(j = total1;j<total1+total2;++j)
                    if(list[j] == 3)break;
                if(j == total1+total2)
                    for(j = 0;j<total1;++j)
                        if(list[j] == 3)break;
                list[j] = list[i];
                list[i] = 3;
                ++exchange;
            }
        }
    }
    for(i = (total1+total2-1);i>=total1;--i)
    {
        if(list[i] != 2)
        {
            for(j = 0;j<total1;++j)
                if(list[j] == 2)break;
            list[j] = list[i];
            list[i] = 2;
            ++exchange;
        }
    }
    cout << exchange<<endl;
    return 0;
}