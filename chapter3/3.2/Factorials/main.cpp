/*
 ID: miyunlu1
 PROG: fact4
 LANG: C++11
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int N;
int main()
{
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    cin >> N;
    string a  = "0001";
    for(int i=2;i<=N;++i)
    {
        stringstream ss;
        int b = stoi(a.c_str());
        b *=i;
        string tmp;
        // ******stringstream是个不错的东西，不过要注意他的写法，与cout的符号相反******  //
        ss << b;
        ss >> tmp;
        /***********************************************************************/
        int len = tmp.length();
        if(tmp[len-1] != '0')
        {
            for(int k = 0;k<4;++k)
            {
                if(len+k-4 >=0)a[k] = tmp[len+k-4];
                else a[k] = '0';
            }
        }
        else{
            int kk;
            for(kk = len-1;kk>=0;--kk) if(tmp[kk] != '0')break;
            for(int k = 0;k<4;++k)
            {
                if(kk+1 +k-4 >=0)a[k] = tmp[kk+1 +k-4];
                else a[k] = '0';
            }
                
        }
    }
    cout << a[3] <<endl;
}

/*
int main()
{
    int aa = 30;
    stringstream sss;
    sss<<aa;
 
    //  *************************这里还有一种写法*************************
    string s1 = sss.str();
    cout<<s1<<endl; // 30
    
    string s2;
    sss>>s2;
    cout<<s2<<endl; // 30
}
*/