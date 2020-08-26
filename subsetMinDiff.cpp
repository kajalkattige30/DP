#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
    return (a<b ? a:b);
}

int minSubsetSumDiff(int arr[], int range, int n){
    int i,j;
    int mn = INT_MAX;
    int T[n+1][range+1];
    vector<int> values;
    for(i=0; i<n+1; i++){
        for(j=0; j<range+1; j++){
            if(i == 0)
                T[i][j] = 0;
            if(j == 0)
                T[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<range+1; j++){
            if(arr[i-1] <= j){
                T[i][j] = (T[i-1][j] || T[i-1][j-arr[i-1]]);
             }
            else
                T[i][j] = T[i-1][j];
        }
    }
    
    for(j=0; j<=range/2; j++){
        if(T[n][j] == 1)
            values.push_back(j);
    }
    
    for(int k=0; k<values.size(); k++){
        mn = min(mn, (range - 2*values[k]));
    }
    return mn;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, sum = 0, mn;
        
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        mn = minSubsetSumDiff(arr, sum, n);
        cout<<mn<<endl;
    }
    return 0;
}