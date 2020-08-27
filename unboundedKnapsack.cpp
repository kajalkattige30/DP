
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a:b);
}

int unboundedKnapsack(int val[], int wt[], int N, int W){
    int i,j;
    int T[N+1][W+1];
    for(i=0; i<N+1; i++){
        for(j=0; j<W+1; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
        }
    }
    for(i=1; i<N+1; i++){
        for(j=1; j<W+1; j++){
            if(wt[i-1] <= j)
                T[i][j] = max(val[i-1] + T[i][j - wt[i-1]], T[i-1][j]);
            else
                T[i][j] = T[i-1][j];
        }
    }
    return T[N][W];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W, maxProfit;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i=0; i<N; i++){
            cin>>val[i];
        }
        for(int i=0; i<N; i++){
            cin>>wt[i];
        }
        maxProfit = unboundedKnapsack(val, wt, N, W);
        cout<<maxProfit<<endl;
    }
    return 0;
}