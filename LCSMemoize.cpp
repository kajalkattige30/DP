#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int max(int a, int b){
    return (a > b ? a : b);
}

int LCS(string X, string Y, int m ,int n){
    if(m == 0 || n == 0)
        return 0;
    if(t[m][n] != -1)
        return t[m][n];
    if(X[m-1] == Y[n-1])
        return t[m][n] = 1+LCS(X, Y, m-1, n-1);
    else
        return t[m][n] = max(LCS(X, Y, m, n-1), LCS(X, Y, m-1, n));
}

int main(){
    string X, Y;
    cin>>X>>Y;
    int m = X.length(), n = Y.length();
    int l;
    memset(t, -1, sizeof(t));
    l = LCS(X, Y, m, n);
    cout<<l<<endl;
    return 0;
}