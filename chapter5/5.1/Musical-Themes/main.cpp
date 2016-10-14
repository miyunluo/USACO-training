/*
 ID: miyunlu1
 PROG: theme
 LANG: C++11
 */
#include <iostream>
using namespace std;
int flow[5001];
int N,maxlen;
int main()
{
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    int f,l;
    cin >> N >> f;
    for(int i = 1;i<N;++i)
    {
        cin >> l;
        flow[i] = l - f;
        f = l;
    }
    for(int s1 = 1;s1<N-maxlen+1;++s1)
        for(int s2 = s1+max(4,maxlen);s2 <N-maxlen+1;++s2)
        {
            if(flow[s1] == flow[s2])
            {
                int a = s1 +1, b = s2+1,len = 1;
                while(a<s2 && b< N && flow[a] == flow[b])
                {++a,++b,++len;}
                if(a == s2) --len;
                maxlen = max(maxlen,len);
            }
        }
    if(maxlen <4)cout << 0<<endl;
    else cout << maxlen +1<<endl;
}
//  Created on 16/5/8.
