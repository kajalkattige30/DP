#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return (a < b ? a : b);
}
int minCoins(int arr[], int sum, int n){
    int i,j, res;
    int T[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(j==0)
                T[i][j] = 0;
            if(i==0)
                T[i][j] = INT_MAX - 1;
        }
    }
    // for(j=1; j<sum+1; j++){
    //     if(j%arr[0] == 0)
    //         T[1][j] = j/arr[0];
    //     else
    //         T[1][j] = INT_MAX - 1;
    // }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                T[i][j] = min((1 + T[i][j - arr[i-1]]), T[i-1][j]);
            }
            else
                T[i][j] = T[i-1][j];
            
        }
    }
    res = T[n][sum];
    if(res == INT_MAX - 1)
        return -1;
    else
        return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, res, S;
        cin>>S>>n;
        int coin[n];
        for(int i=0; i<n; i++){
            cin>>coin[i];
        }
        
        res = minCoins(coin, S, n);
        cout<<res<<endl;
    }
    return 0;
}