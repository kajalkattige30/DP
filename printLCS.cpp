#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

string LCS(char X[], char Y[], int m, int n){
    int i,j;
    int T[m+1][n+1];
    string s;
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
                T[i][j] = max(T[i-1][j], T[i][j-1]);
        }
    }
    i = m, j = n;
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if(T[i-1][j] > T[i][j-1])
                i--;
            
            else
                j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        string R;
        cin>>m>>n;
        char X[m], Y[n];
        for(int i=0; i<m; i++){
            cin>>X[i];
        }
        for(int i=0; i<n; i++){
            cin>>Y[i];
        }
        R = LCS(X, Y, m, n);
        cout<<R<<endl;
    }
}