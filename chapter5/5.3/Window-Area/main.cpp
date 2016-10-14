/*
 ID: miyunlu1
 PROG: window
 LANG: C++11
 */
#include <iostream>
#include <cmath>
using namespace std;
struct square{
    int x1,y1, x4,y4;
    int s;//window area
    char mark;
    square* pre,*next;
    square(char m,int a,int b,int c,int d)
    {
        mark = m;
        x1 = min(a,c),y1 = min(b,d);
        x4 = max(a,c),y4 = max(b,d);
        s = (x4 - x1) * (y4 - y1);
        pre = NULL;next = NULL;
    }
    square(){s = 0;x1=x4=y1=y4 = 0;mark = '*';pre = NULL;next = NULL;}
};
square* list[120];
square* bottom,*top;

int DFS(int x1,int y1,int x4,int y4,square* s)
{
    while(s!= top && ((s->x1 >= x4) || (s->x4 <= x1) || (s->y4 <= y1) || (s->y1 >= y4)))s = s->next;
    if(s == top)
        return ((x4 - x1)*(y4 - y1));
    
    int blank = 0;
    if(s->y1 > y1) {blank += DFS(x1,y1,x4,s->y1,s->next);y1 = s->y1;}
    if(s->y4 < y4) {blank += DFS(x1,s->y4,x4,y4,s->next);y4 = s->y4;}
    if(s->x4 < x4) {blank += DFS(s->x4,y1,x4,y4,s->next);x4 = s->x4;}
    if(s->x1 > x1) {blank += DFS(x1,y1,s->x1,y4,s->next);x1 = s->x1;}
    return blank;
}
int main()
{
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    char com;
    bottom = new square(), top = new square();
    bottom->next = top;top->pre = bottom;
    while(cin >> com)
    {
        if(com == 'w')// product
        {
            char m;
            int a,b ,c,d;
            cin.get();cin >>m;cin.get();cin>>a;cin.get();cin>>b;cin.get();cin>>c;cin.get();cin>>d;cin.get();
            list[m-'0'] = new square(m,a,b,c,d);
            square* tmp = top->pre;
            tmp->next = list[m-'0'];list[m-'0']->pre = tmp;
            list[m-'0']->next = top;top->pre = list[m-'0'];
        }
        if(com == 't')// move to top
        {
            char m;
            cin.get();cin >> m;cin.get();
            square * p=list[m-'0']->pre, * n = list[m-'0']->next;
            p->next = n,n->pre = p;
            square* tmp = top->pre;
            tmp->next = list[m-'0'];list[m-'0']->pre = tmp;
            list[m-'0']->next = top;top->pre = list[m-'0'];
        }
        if(com == 'b')// move to bottom
        {
            char m;
            cin.get();cin >> m;cin.get();
            square * p=list[m-'0']->pre, * n = list[m-'0']->next;
            p->next = n,n->pre = p;
            square* tmp = bottom->next;
            tmp->pre = list[m-'0'],list[m-'0']->next = tmp;
            list[m-'0']->pre = bottom,bottom->next = list[m-'0'];
        }
        if(com == 'd')//delete
        {
            char m;
            cin.get();cin >> m;cin.get();
            square * p=list[m-'0']->pre, * n = list[m-'0']->next;
            p->next = n,n->pre = p;
            delete list[m-'0'];
        }
        if(com == 's')
        {
            char m;
            cin.get();cin >> m;cin.get();
            int ans = DFS(list[m-'0']->x1,list[m-'0']->y1,list[m-'0']->x4,list[m-'0']->y4,list[m-'0']->next);
            double percent = (100.0 * ans) / list[m-'0']->s;
            printf("%.3lf\n",percent);
        }
    }
}

//  Created on 16/5/11.
/*
 w(a,10,132,20,12)
 w(b,8,76,124,15)
 s(a)
 
 w(a,1,1,21,21)
 w(b,2,2,12,12)
 w(c,5,5,8,8)
 s(a)
 s(c)
 s(b)
 */
