#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int static T[1001][1001];

int count(int arr[], int i, int j){
    int k;
    if(i >= j)
        return 0;
    if(T[i][j] != -1)
        return T[i][j];
    int mn = INT_MAX;
    for(k=i; k<j; k++){
        int temp = count(arr, i, k) + count(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(temp < mn)
            mn = temp;
    }
    return T[i][j] = mn;
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, res;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    memset(T, -1, sizeof(T));
	    res = count(a, 1, n-1);
	    cout<<res<<endl;
	}
	return 0;
}