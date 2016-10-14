/*
 ID: miyunlu1
 PROG: humble
 LANG: C++11
 */
#include <iostream>
using namespace std;
/************************* 良哥指点 必须经典 *********************************/
int nindex[101] = {0};
unsigned long setsu[101];//保存素数集合
unsigned long mult[101];//保存乘积
unsigned long result[100004];
int reindex;
int N,di;
int main()
{
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    cin >> N >> di;
    for(int i = 0;i<N;++i) {cin >> setsu[i];mult[i] = setsu[i];}
    result[reindex++] = 1;
    for(;;)
    {
        unsigned long minn = mult[0];
        for(int i = 0;i<N;++i) minn = ((minn > mult[i]) ? mult[i] : minn);
        result[reindex++] = minn;
        for(int i  = 0;i<N;++i) if(mult[i] == minn) {++nindex[i];mult[i] = result[nindex[i]] * setsu[i];}
        if(reindex == di+2)break;
    }
    cout << result[di]<<endl;
    return 0;
}
/*
2 7
3 5

*/