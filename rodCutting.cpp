#include <iostream>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

int cutRod(int price[], int n){
    int i,j;
    int T[n+1][n+1];
    int arr[n];
    for(int k=0; k<n; k++){
        arr[k] = k+1;
    }
    for(i=0; i<n+1; i++){
        for(j=0; j<n+1; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<n+1; j++){
            if(arr[i-1] <= j){
                T[i][j] = max(price[i-1] + T[i][j - arr[i-1]], T[i-1][j]);
            }
            else
            {
                T[i][j] = T[i-1][j];
            }
            
        }
    }
    return T[n][n];
}

int main() {
	int t;
    cin>>t;
    while(t--){
        int n, maxPrice;
        cin>>n;
        int price[n];
        for(int i=0; i<n; i++){
            cin>>price[i];
        }
        maxPrice = cutRod(price, n);
        cout<<maxPrice<<endl;
    }
	return 0;
}