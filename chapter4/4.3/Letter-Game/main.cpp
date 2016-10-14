/*
 ID: miyunlu1
 PROG: lgame
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int weight[26]={2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
map<string, int> dict;
map<string, int> Hash;
vector<string> ans;

int calc(string w)
{
    int value = 0;
    for(auto i = 0;i<w.size();++i)value += weight[w[i] - 'a'];
    return value;
}
int main()
{
    freopen("lgame.dict", "r", stdin);
    string word;
    while((cin >> word) && word != ".")
        dict[word] = calc(word);
    dict[""] = 0;
    fclose(stdin);
    
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    
    cin >> word;
    sort(word.begin(),word.end());
    int ansnum = 0;

    do{
        int v1 = 0,v2 = 0;
        for(int i = 1;i<=word.size();++i)
            for(int j = 0;j<=word.size()-i;++j)
            {
                v1 = dict[word.substr(0,i)];
                v2 = dict[word.substr(i,j)];
                if(v1 == 0) continue;
                if((j>0) && word.substr(0,i)>word.substr(i,j)) continue;
                
                string tmp = word.substr(0,i);
                if(j>0) tmp += " " + word.substr(i,j);
                
                if(j>0 && v2 == 0) continue;
                
                if(ansnum < v1 + v2)
                {
                    ansnum = v1 + v2;
                    Hash.clear();
                    ans.clear();
                    ans.push_back(tmp);
                    Hash[tmp] = 1;
                }
                else if(ansnum == v1 + v2)
                {
                    if(!Hash[tmp])
                    {++Hash[tmp];ans.push_back(tmp);}
                }
            }
    }while(next_permutation(word.begin(), word.end()));
    
    cout << ansnum<<endl;
    for(int i = 0;i<ans.size();++i)cout << ans[i]<<endl;
    return 0;
}

//  Created on 16/4/29.

