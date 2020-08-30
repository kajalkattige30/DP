#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LCSubstring(char X[], char Y[], int n, int m){
    int i, j, max = 0;
    int T[n+1][m+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<m+1; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<m+1; j++){
            if(X[i-1] == Y[j-1])
                T[i][j] = 1 + T[i-1][j-1];
            else
                T[i][j] = 0;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<m+1; j++){
            if(T[i][j] > max)
                max = T[i][j];
        }
    }
    return max;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, length;
        cin>>n>>m;
        char X[n], Y[m];
        for(int i=0; i<n; i++){
            cin>>X[i];
        }
        for(int i=0; i<m; i++){
            cin>>Y[i];
        }
        length = LCSubstring(X, Y, n, m);
        cout<<length<<endl;
    }
    return 0;
}