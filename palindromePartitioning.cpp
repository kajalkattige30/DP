#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int static T[1001][1001];

bool isPalindrome(string s, int i, int j){
    if(i >= j)
        return true;
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j){
    int left, right;
    if(i >= j)
        return 0;
    if(isPalindrome(s, i, j) == true)
        return 0;
    if(T[i][j] != -1)
        return T[i][j];
    int mn = INT_MAX;
    for(int k = i; k<=j-1; k++){
        if(T[i][k] != -1)
            left = T[i][k];
        else
            left = solve(s, i, k);
            T[i][k] = left;
        if(T[k+1][j] != -1)
            right = T[k+1][j];
        else
            right = solve(s, k+1, j);
            T[k+1][j] = right;
        
        int temp = 1+left+right;
        
        if(temp < mn)
            mn = temp;
    }
    return T[i][j] = mn;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int i, j, n, res;
	    n = s.length();
	    memset(T, -1, sizeof(T));
	    res = solve(s, 0, n-1);
	    cout<<res<<endl;
	}
	return 0;
}