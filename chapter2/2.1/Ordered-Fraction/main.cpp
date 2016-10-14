/*
 ID: miyunlu1
 PROG: frac1
 LANG: C++11
 */
#include <iostream>
using namespace std;

struct node{
    int up,down;
    node *next;
    node(int u,int d){up = u;down = d;next = NULL;}
    node(){next = NULL;}
};
int N;
node*head = new node(0,1);
node*tail = new node(1,1);

void Russ(node*lf,node*rt)
{
    if((lf->down + rt->down) > N)return;
    int fenzi = lf->up + rt->up;
    int fenmu = lf->down + rt->down;
    //cout << fenzi <<' '<<fenmu<<endl;
    node *tmp = new node(fenzi,fenmu);
    tmp->next = rt;
    lf->next = tmp;
    Russ(lf,tmp);
    Russ(tmp,rt);
}
int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out","w",stdout);
    cin >> N;
    head->next = tail;
    Russ(head,tail);
    node *p = head;
    while(p != NULL) {cout << p->up << '/' << p->down << endl;p = p->next;}
    return 0;
}
