class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int s, sum = 0, c = 0, res, i, j;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(nums[i] == 0)
                c +=1;
        }
        if(sum<S) {
            return 0;
        }
        if((sum-S)%2!=0){
            return 0;
        }
        s = (sum - S)/2;
        
        int t[n+1][s+1];
        for(i=0; i<n+1; i++){
            for(j=0; j<s+1; j++){
                if(i==0)
                        t[i][j] = 0;
                if(j==0)
                        t[i][j] = 1;
            }
        }
        for(i=1; i<n+1; i++){
            for(j=1; j<s+1; j++){
                if(nums[i-1] == 0){
                    t[i][j] = t[i-1][j];
                }
                else if(j < nums[i-1]){
                    t[i][j] = t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
            }
        }
        return pow(2,c)*t[n][s];

    }
};
