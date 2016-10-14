/*
 ID: miyunlu1
 PROG: zerosum
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iterator>
//#include <algorithm>
using namespace std;
int N;
string aa;
vector<string> ans;
void calculate(string& a)
{
    queue<int> shuzi;
    queue<char> fuhao;
    unsigned long len = a.size();
    int dex = 0;
    while(dex <= len)
    {
        if(a[dex] == '-' || a[dex] == '+') {fuhao.push(a[dex]);++dex;continue;}
        else{
            string tmp;
            while(a[dex] !='-' && a[dex] != '+')
            {
                if(a[dex] == ' '){++dex;continue;}
                tmp += a[dex];
                ++dex;
            }
            int value = stoi(tmp);
            shuzi.push(value);
        }
    }
    int result = shuzi.front();shuzi.pop();
    while(!fuhao.empty())
    {
        char jisuan = fuhao.front();fuhao.pop();
        long second = shuzi.front();shuzi.pop();
        switch(jisuan){
            case '+':result += second;break;
            case '-':result -= second;break;
        }
    }
    if(result == 0)ans.push_back(a);
}
void makestring(string a,int num)
{
    if(num == N)
    {
        a += '0'+num;
        calculate(a);
        return;
    }
    a += '0'+num;
    int i;
    for(i = 0;i<3;++i)//此顺序保证了不需要再排序了，已经按照ascall顺序
    {
        if(i == 0){string a1 = a;a1 += ' '; makestring(a1, num+1);}
        if(i == 1){string a1 = a;a1 += '+'; makestring(a1, num+1);}
        if(i == 2){string a1 = a;a1 += '-'; makestring(a1, num+1);}
    }
}
void display()
{
    //sort(ans.begin(),ans.end());
    vector<string>::iterator lf = ans.begin(),rt = ans.end();
    for(;lf!=rt;++lf)cout << *lf <<endl;
}
int main()
{
    //freopen("zerosum.in", "r", stdin);
    //freopen("zerosum.out", "w", stdout);
    cin >> N;
    makestring(aa, 1);
    display();
    return 0;
}

/*
 1+2-3+4-5-6+7
 1+2-3-4+5+6-7
 1-2 3+4+5+6+7
 1-2 3-4 5+6 7
 1-2+3+4-5+6-7
 1-2-3-4-5+6+7
*/