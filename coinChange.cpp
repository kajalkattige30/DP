#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(int arr[], int sum, int n){
    int i,j;
    int T[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i==0)
                T[i][j] = 0;
            if(j==0)
                T[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j)
                T[i][j] = (T[i-1][j] + T[i][j - arr[i-1]]);
            else
                T[i][j] = T[i-1][j];
        }
    }
    return T[n][sum];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n, res;
        cin>>m;
        int coin[m];
        for(int i=0; i<m; i++){
            cin>>coin[i];
        }
        cin>>n;
        res = coinChange(coin, n, m);
        cout<<res<<endl;
    }
    return 0;
}