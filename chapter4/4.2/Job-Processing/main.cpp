/*
 ID: miyunlu1
 PROG: job
 LANG: C++11
 */
#include <iostream>
using namespace std;
#define N 1000
#define M 30
#define INF 0x7fffffff
int timeJA[N],timeJB[N],timeA[M],timeB[M];
int endA[M],endB[M];
int job,nA,nB;
int main()
{
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    cin >> job >> nA >> nB;
    for(int i = 0;i<nA;++i) cin >>timeA[i];
    for(int i = 0;i<nB;++i) cin >>timeB[i];
    
    for(int i = 0;i<job;++i){
        int T = INF,useA = -1;
        for(int j = 0;j<nA;++j)
        {
            if(endA[j] + timeA[j] < T)
            {T = endA[j] + timeA[j];useA = j;}
        }
        timeJA[i] = T;
        endA[useA] += timeA[useA];
    }
    int ansA = 0;
    for(int i = 0;i<nA;++i)if(ansA < endA[i]) ansA = endA[i];
    //cout << ansA<<endl;
    
    //for(int i = 0;i<job;++i)cout << timeJA[i];
    //cout <<endl;
    for(int i = 0;i<job;++i){
        int T = INF,useB = -1;
        for(int j = 0;j<nB;++j)
        {
            if(endB[j] + timeB[j] < T)
            {T = endB[j] + timeB[j];useB = j;}
        }
        timeJB[i] = T;
        endB[useB] += timeB[useB];
    }
    int ansB = 0;
    for(int i = 0;i<job;++i)
        if(timeJA[i] + timeJB[job-1-i] > ansB)ansB = timeJA[i] + timeJB[job-1-i];
    cout << ansA << ' '<< ansB <<endl;
    
}
//
//  main.cpp
//  Job Processing 工序安排
//
//  Created by 罗煜东 on 16/4/24.
//  Copyright © 2016年 芈云落. All rights reserved.
//
/*
 5 2 3
 1 1 3 1 4
 */

