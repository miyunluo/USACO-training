/*
 ID: miyunlu1
 PROG: fracdec
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
/*******************************    此题写的像坨屎     *************************************/
bool presnet[100000] = {false};
struct synode{
    int ss;
    int ys;
};
vector<synode> llist;
int main()
{
    //freopen("fracdec.in", "r", stdin);
    //freopen("fracdec.out", "w", stdout);
    int a,b;
    cin >> a >> b;
    
    if(a % b == 0){cout << a/b <<".0"<<endl;return 0;}
    
    int front = a / b;
    int yushu = a % b;
    synode p;
    p.ss = 0;p.ys = yushu;presnet[yushu] = true;
    llist.push_back(p);
    yushu *= 10;
    
    int k=0,f = front;
    if(f == 0) k = 1;
    else while(f){f /= 10;k++;}
    
    for(;;)
    {
        synode tmp;
        tmp.ss = yushu / b;
        tmp.ys = yushu % b;
        yushu = tmp.ys * 10;
        
        if(yushu == 0)
        {
            llist.push_back(tmp);
            cout << front<<'.';
            int cont = k + 1;
            for(auto i = llist.begin()+1;i != llist.end();++i)
            {
                cout << i->ss;
                ++cont;
                if(cont == 76){cout << endl;cont = 0;}
            }
            if(cont != 0)cout << endl;
            break;
        }
        
        if(presnet[tmp.ys]){
            auto i = llist.begin();
            for(;i != llist.end();++i){
                if(i->ys == tmp.ys)break;
            }
        
            
            cout << front << '.';
            int cont = k + 1;
            
            if(i == llist.begin())
            {
                ++i;
                cout <<'(';
                ++cont;
                for(;i != llist.end();++i)
                {
                    cout <<i->ss;
                    ++cont;
                    if(cont == 76){cout << endl;cont = 0;}
                }
                cout << tmp.ss;++cont;
                if(cont == 76){cout << endl;cont = 0;}
                cout <<')'<<endl;
            }
            else{
                //吼吼，注意迭代器由于加入元素而发生改变！
                for(auto j = llist.begin()+1;j != i;++j)
                {
                    cout << j->ss;
                    ++cont;
                    if(cont == 76){cout << endl;cont = 0;}
                }
                cout << i->ss;
                ++cont;
                if(cont == 76){cout << endl;cont = 0;}
                cout << '(';
                ++cont;
                if(cont == 76){cout << endl;cont = 0;}
                ++i;
                for(;i != llist.end();++i)
                {
                    cout << i->ss;
                    ++cont;
                    if(cont == 76){cout << endl;cont = 0;}
                }
                cout << tmp.ss;
                ++cont;
                if(cont == 76){cout << endl;cont = 0;}
                cout << ')' <<endl;
            }
            break;
        }
        else {llist.push_back(tmp);presnet[tmp.ys] = true;}
    }
    return 0;
}