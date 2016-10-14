/*
 ID: miyunlu1
 PROG: transform
 LANG: C++11
 */
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;



int n;
char a[100][100],b[100][100];

int minmethod = 7;

void tran90()
{
    char tmp[100][100];
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            tmp[j][n-i-1] = a[i][j];
    
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            a[i][j] = tmp[i][j];
    
    
}


void fanz()
{
    char tmp[100][100];
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            tmp[i][n-j-1] = a[i][j];
    
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            a[i][j] = tmp[i][j];
}

void compare(int x)
{
    bool flag = true;
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            if(b[i][j] != a[i][j]){flag = false;break;}
    if(flag) minmethod = min(minmethod,x);
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    
    scanf("%d",&n);
    
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j) cin>>a[i][j];
    for(i=0;i<n;++i)
        for(j=0;j<n;++j) cin>>b[i][j];
    
    compare(6); //不做变化
    
    tran90();       //转90度
    compare(1);
    
    tran90();     //转180度
    compare(2);
    
    tran90();    //转270度
    compare(3);
    
    
    tran90();
    fanz();      //翻转
    compare(4);
    
    for(int i=1;i<=3;i++)
    {
        tran90();
        compare(5);
    }
    
    printf("%d\n",minmethod);
    return 0;
    
}


/*
 1：转90度：图案按顺时针转90度。
 2：转180度：图案按顺时针转180度。
 3：转270度：图案按顺时针转270度。
 4：反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
 5：组合：图案在水平方向翻转，然后再按照1到3之间的一种再次转换。
 6：不改变：原图案不改变。
 7：无效转换：无法用以上方法得到新图案。
 */

