#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int diff(int a[], int range, int n){
    int mn = INT_MAX;
    int i,j;
    int t[n+1][range+1];
    vector<int> v;
    for(i=0; i<n+1; i++){
        for(j=0; j<range+1; j++){
            if(i == 0)
                t[i][j] = 0;
            if(j == 0)
                t[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<range+1; j++){
            if(a[i-1] <= j){
                t[i][j] = (t[i-1][j] || t[i-1][j-a[i-1]]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }

    for(j=0; j<=range/2; j++){
        if(t[n][j] == 1){
            v.push_back(j);
        }
    }
    for(int k=0; k<v.size(); k++){
        mn = min(mn, (range - 2*v[k]));
    }

    return mn;
}

int main(){
    int n, sum = 0, res;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    res = diff(arr, sum, n);
    cout<<res<<endl;
    return 0;
}