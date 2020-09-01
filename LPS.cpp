#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

string reverseStr(string str){
    int n = str.length();
    for(int i=0; i<n/2; i++){
        swap(str[i], str[n-i-1]);
    }
    return str;
}

int LPS(string X, string Y){
    int i, j;
    int m = X.length(), n = Y.length();
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
                T[i][j] = 1+T[i-1][j-1];
            else
                T[i][j] = max(T[i][j-1], T[i-1][j]);
        }
    }
    return T[m][n];
}
int main(){
    string a, b;
    int r;
    cin>>a;
    r = LPS(a, reverseStr(a));
    cout<<r<<endl;
    return 0;
}