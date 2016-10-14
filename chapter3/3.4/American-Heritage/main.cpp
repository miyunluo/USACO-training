/*
 ID: miyunlu1
 PROG: heritage
 LANG: C++11
 */
#include <iostream>
#include <string>
using namespace std;
string midOrder,preOrder;
void solve(string pre, string mid)
{
    if (pre.size() <= 1)
    {
        if (pre.size() == 1)
            cout << pre[0];
        return;
    }
    int index = int(mid.find(pre[0]));
    string left_Pre = pre.substr(1, index);
    string right_Pre = pre.substr(index+1, pre.size()-1-index);
    string left_In = mid.substr(0, index);
    string right_In = mid.substr(index+1, mid.size()-1-index);
    solve(left_Pre, left_In);//左
    solve(right_Pre, right_In);//右
    cout << pre[0];//根
    return;
}
/*
node * buildTree(string midstr,string prestr)
{
    if(midstr.length() == 1)
    {
        node *t = new node(midstr[0]);
        return t;
    }
    int m;
    for(m = 0;m<midstr.length();++m)
        if(midstr[m] == prestr[0])break;
    node * tmp = new node(prestr[0]);
    tmp->lf = buildTree(midstr.substr(0,m), prestr.substr(1,m));
    tmp->rt = buildTree(midstr.substr(m+1), prestr.substr(m+1));
    return tmp;
}*/
int main()
{
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    cin >> midOrder >> preOrder;
    solve(preOrder, midOrder);
    cout << endl;
    return 0;
}