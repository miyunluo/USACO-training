/*
 ID: miyunlu1
 PROG: beads
 LANG: C++11
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/*
int main()
{
    //freopen("beads.in","r", stdin);
    //freopen("beads.out", "w", stdout);
    
    int len,i;
    scanf("%d",&len);
    
    char in[len+1];
    scanf("%s",in);
    //cout << len <<endl;
    //cout << in <<endl;
    char lace[len *2 +1];
    for(i=0;i<len;++i) {lace[i] = lace[len+i] = in[i];}
    lace[len *2 +1] = '\0';
    //cout<<lace<<endl;
    
    int bluetime,redtime,maxlen = 0,tmp;
    char form;
    bool bluepre = false,redpre = false;
    for(i=0;i<len;++i)
    {
        //cout <<"i:"<<i<<endl;
        bluetime = redtime = tmp = 0;
        form = 'w';
        while(bluetime <= 1 && redtime <= 1)
        {
            if(lace[i] == 'w') {form = 'w';++i;++tmp;continue;}
            
            if(lace[i] == 'b')
            {
                if(!bluepre){bluepre = true;form = 'b';++i;++tmp;++bluetime;continue;}
                else
                {
                    if(form == 'b' || form == 'w'){form = 'b';++i;++tmp;continue;}
                    else ++ bluetime;
                }
            }
            
            if(lace[i] == 'r')
            {
                if(!redpre){redpre = true;form = 'r';++i;++tmp;++redtime;continue;}
                else
                {
                    if(form == 'r' || form =='w'){form = 'r';++i;++tmp;continue;}
                    else ++ bluetime;
                }
            }
            
            
        }
        
        cout << "i:"<< i <<' '<< tmp << endl;
        maxlen = max(maxlen,tmp);
    }
    
    printf("%d",maxlen);
    
    return 0;
}
*/

/*
int main()
{
    //freopen("beads.in","r",stdin);
    //freopen("beads.out","w",stdout);
    int n;
    int maxlen=0;
    int temp;
    char change;
    int i,j,k;
    
    scanf("%d",&n);
    char bead[1000];
    scanf("%s",bead);
    
    
    for(i=0;i<n;i++)
    {
        if(n==1){maxlen = 1;break;}
        
        temp = 2;
        change = 'w';
        for(j=1;j<(n-1);j++)
        {
            
            if((bead[i] == bead[(i+j)%n]) || (bead[(i+j)%n] == 'w')) temp++;
            
            else if(bead[i] == 'w' && change == 'w')
            {
                change = bead[(i+j)%n];
                temp++;
            }
            else if(bead[i] == 'w' && bead[(i+j)%n] == change) temp++;
            
            else break;
        }
        change='w';

        for(k=1;k<(n-1)&&(k+j)<n;k++)
        {
            
            if((bead[i-1] == bead[(i-1+n-k)%n]) || (bead[(i-1+n-k)%n] == 'w'))
            {
                temp++;
            }
            else if(bead[i-1] == 'w'&&change == 'w')
            {
                change = bead[(i-1+n-k)%n];
                temp++;
            }
            else if(bead[i-1] == 'w' && bead[(i-1+n-k)%n] == change)
            {
                temp++;
            }
            else
                break;
        }
       
        maxlen = max(maxlen,temp);
    }
    printf("%d",maxlen);
    return 0;
}
*/

int main()
{
    int blueleft[50001] = {0},redleft[50001]={0},blueright[50001]={0},redright[50001]={0};
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int n,i;
    string str;
    scanf("%d",&n);
    //scanf("%s",str);
    cin  >> str;
    str = str + str;
    
    for(i=0;i<2*n;++i)
    {
        if(str[i] == 'r') {redleft[i] = redleft[i-1] +1;blueleft[i] = 0;}
        if(str[i] == 'b') {blueleft[i] = blueleft[i-1] +1; redleft[i] = 0;}
        if(str[i] == 'w') {redleft[i] = redleft[i-1] +1;blueleft[i] = blueleft[i-1] +1;}
    }
    
    for(i=2*n-1;i>=0;--i)
    {
        if(str[i] == 'r') {redright[i] = redright[i+1] +1;blueright[i] = 0;}
        if(str[i] == 'b') {blueright[i] = blueright[i+1] +1; redright[i] = 0;}
        if(str[i] == 'w') {redright[i] = redright[i+1] +1;blueright[i] = blueright[i+1] +1;}
    }
    
    int maxlen = 0,tmp;
    for(i=0;i<n*2;++i)
    {
        tmp = max(redleft[i],blueleft[i])+max(redright[i+1],blueright[i+1]);
        maxlen = max(maxlen,tmp);
    }
    maxlen = min(maxlen,n); //如果出现全为同一种颜色的情况
    
    printf("%d\n",maxlen);
    
    return 0;
}




