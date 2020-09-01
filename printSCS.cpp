#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

string SCS(string X, string Y, int m, int n){
    int i, j;
    int T[m+1][n+1];
    string r;
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
    i = m, j = n;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            r.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if(T[i][j-1] > T[i-1][j]){
                r.push_back(Y[j-1]);
                j--;
            }
            else{
                r.push_back(X[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        r.push_back(X[i-1]);
        i--;
    }
    while(j>0){
        r.push_back(Y[j-1]);
        j--;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main(){
    
    string X, Y;
    cin>>X>>Y;
    int m = X.length(), n = Y.length();
    string res;
    res = SCS(X, Y, m, n);
    cout<<res<<endl;

    return 0;

}