#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

int shortestSupersequence(string X, string Y){
    int i, j, l, res;
    int m = X.length(), n = Y.length();
    string S;
    int T[m+1][n+1];
    for(i=0; i<m+1; i++){
        for(j=0; j<n+1; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
        }
    }
    for(i=1; i<m+1; i++){
        for(j=1; j<n+1; j++){
            if(X[i-1] == Y[j-1])
                T[i][j] = 1 + T[i-1][j-1];
            else
                T[i][j] = max(T[i][j-1], T[i-1][j]);
        }
    }
    l = T[m][n];
    res = m + n - l;
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string X, Y;
        cin>>X>>Y;
        int r;
        r = shortestSupersequence(X, Y);
        cout<<r<<endl;
    }
    return 0;
}