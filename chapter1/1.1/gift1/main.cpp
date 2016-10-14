/*
 ID: miyunlu1
 PROG: gift1
 LANG: C++11
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int n, t, a, b;
char tmp[15], f[15];
struct E{
    char name[15];
    int money;
}buf[11];

//查找姓名所在的位置
int find(char *p)
{
    int i;
    for(i = 1; i <= n; i++)
        if(!strcmp(p, buf[i].name))
            return i;
    return i;
}

int main(){
    freopen("gift1.in","r", stdin);
    freopen("gift1.out", "w", stdout);
    //读入人数
    cin >> n;
    //读入所有人的名字
    for(int i = 1; i <= n; i++){
        buf[i].money = 0;
        cin >>buf[i].name;
    }
    while(~scanf("%s", tmp)) //当输入的不是EOF  ~按位取反不是0
    {
        cin >> a >>b;
        if(!b) continue;  //如果b是0，不给人发钱
        
        int av = a / b;
        buf[find(tmp)].money -= av * b;//分发gift的money - av * b;
        //被分发gift分到a / b数目的money
        while(b--){
            scanf("%s", f);
            buf[find(f)].money += av;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%s %d\n", buf[i].name, buf[i].money);
    return 0;
}