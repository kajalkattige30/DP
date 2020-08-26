#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subsetSumCount(int a[], int sum, int n){
    int i,j;
    int t[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i == 0)
                t[i][j] = 0;
            if(j == 0)
                t[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(a[i-1] <= j){
                t[i][j] = (t[i-1][j - a[i-1]] + t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
            
        }
    }
    return t[n][sum];
}
int main(){
    int n, k, count;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;
    count = subsetSumCount(arr, k, n);
    cout<<count<<endl;
    return 0;
}