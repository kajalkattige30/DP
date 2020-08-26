#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
bool subsetSum(int a[], int sum, int n){
    int i,j;
    bool t[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(a[i-1] <= j){
                t[i][j] = (t[i-1][j - a[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int n, sum = 0;
    bool res;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum%2 == 0){
        int s = sum/2;
        res = subsetSum(arr, s, n);
        if(res == true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}