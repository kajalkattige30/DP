// is "a" subsequence of "b"?
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

bool SPM(char X[], char Y[], int m, int n){
    int i, j;

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
            {
                T[i][j] = max(T[i][j-1], T[i-1][j]);
            }
            
        }
    }
    if(m == T[m][n])
        return true;
    else
        return false;

}
int main(){
    int m, n;
    cin>>m>>n;
    char X[m], Y[n];
    bool res;
    for(int i=0; i<m; i++){
        cin>>X[i];
    }
    for(int i=0; i<n; i++){
        cin>>Y[i];
    }
    res = SPM(X, Y, m,n);
    if(res == "1")
        cout<<"true"<<endl;
    else
    {
        cout<<"false"<<endl;
    }
    

    return 0;
}