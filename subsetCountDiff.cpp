#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int sum, int n){
    int i,j;
    int t[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    return t[n][sum];
}
int main(){
    int n, sum = 0, res, diff, s;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cin>>diff;
    s = (sum - diff)/2;
    res = count(arr, s, n);
    cout<<s<<endl;
    return 0;
}