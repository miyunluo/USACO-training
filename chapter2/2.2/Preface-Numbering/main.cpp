/*
 ID: miyunlu1
 PROG: preface
 LANG: C++11
 */
#include <iostream>
#include <string>
using namespace std;
string a[4][10];
int sum[7];

void initialize()
{
    //个位
    a[0][1] = "I";a[0][2] = "II";a[0][3] = "III";a[0][4] = "IV";a[0][5] = "V";
    a[0][6] = "VI";a[0][7] = "VII";a[0][8] = "VIII";a[0][9] = "IX";
    //十位
    a[1][1] = "X";a[1][2] = "XX";a[1][3] = "XXX";a[1][4] = "XL";a[1][5] = "L";
    a[1][6] = "LX";a[1][7] = "LXX";a[1][8] = "LXXX";a[1][9] = "XC";
    //百位
    a[2][1] = "C";a[2][2] = "CC";a[2][3] = "CCC";a[2][4] = "CD";a[2][5] = "D";
    a[2][6] = "DC";a[2][7] = "DCC";a[2][8] = "DCCC";a[2][9] = "CM";
    //千位
    a[3][1] = "M";a[3][2] = "MM";a[3][3] = "MMM";
}

void convy(int x)
{
    int wei = 0;
    string tmp;
    while((x/10) != 0)
    {
        tmp = a[wei][x%10];
        string::iterator lf = tmp.begin(),rt = tmp.end();
        while(lf != rt)
        {
            switch(*lf)
            {
                case 'I':++sum[0];break;
                case 'V':++sum[1];break;
                case 'X':++sum[2];break;
                case 'L':++sum[3];break;
                case 'C':++sum[4];break;
                case 'D':++sum[5];break;
                case 'M':++sum[6];break;
            }
            ++lf;
        }
        x /= 10;
        ++wei;
    }
    
    tmp = a[wei][x];
    string::iterator lf = tmp.begin(),rt = tmp.end();
    while(lf != rt)
    {
        switch(*lf)
        {
            case 'I':++sum[0];break;
            case 'V':++sum[1];break;
            case 'X':++sum[2];break;
            case 'L':++sum[3];break;
            case 'C':++sum[4];break;
            case 'D':++sum[5];break;
            case 'M':++sum[6];break;
        }
        ++lf;
    }
}
void display()
{
    for(int i = 0;i<7;++i)
    {
        if(i == 0 && sum[i] !=0)cout << 'I' <<' '<<sum[i]<<endl;
        if(i == 1 && sum[i] !=0)cout << 'V' <<' '<<sum[i]<<endl;
        if(i == 2 && sum[i] !=0)cout << 'X' <<' '<<sum[i]<<endl;
        if(i == 3 && sum[i] !=0)cout << 'L' <<' '<<sum[i]<<endl;
        if(i == 4 && sum[i] !=0)cout << 'C' <<' '<<sum[i]<<endl;
        if(i == 5 && sum[i] !=0)cout << 'D' <<' '<<sum[i]<<endl;
        if(i == 6 && sum[i] !=0)cout << 'M' <<' '<<sum[i]<<endl;
    }
}
int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int N;
    cin >> N;
    initialize();
    for(int i = 1;i<=N;++i)
        convy(i);
    display();
    return 0;
}