/*
 ID: miyunlu1
 PROG: namenum
 LANG: C++11
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


int main()
{
    ifstream fin("namenum.in");
    ifstream rfile("dict.txt");
    ofstream fout("namenum.out");
    
    char in[13];
    char *tmp1,*tmp2;
    tmp1 = new char[13];
    tmp2 = new char[13];
    fin >> in;
    bool flag = false;
    while(rfile >> tmp1)
    {
        int len = strlen(tmp1);
        int i;
        for(i=0;i<len;++i)
        {
            switch(tmp1[i])
            {
                case 'A':case 'B':case 'C':
                    tmp2[i] = '2';
                    break;
                case 'D':case 'E':case 'F':
                    tmp2[i] = '3';
                    break;
                case 'G':case 'H':case 'I':
                    tmp2[i] = '4';
                    break;
                case 'J':case 'K':case 'L':
                    tmp2[i] = '5';
                    break;
                case 'M':case 'N':case 'O':
                    tmp2[i] = '6';
                    break;
                case 'P':case 'R':case 'S':
                    tmp2[i] = '7';
                    break;
                case 'T':case 'U':case 'V':
                    tmp2[i] = '8';
                    break;
                case 'W':case 'X':case 'Y':
                    tmp2[i] = '9';
            }
        }
        tmp2[i] = '\0';
        
        if(strcmp(in,tmp2) == 0) {fout << tmp1 <<'\n';flag = true;}
    }
    
    if(!flag) fout <<"NONE"<<'\n';
    
    return 0;
}

/*
              2: A,B,C    3: D,E,F
 4: G,H,I     5: J,K,L    6: M,N,O
 7: P,R,S     8: T,U,V    9: W,X,Y
*/