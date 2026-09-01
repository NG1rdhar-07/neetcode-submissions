class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int cnt = 0;

        if(abs(target) > s)
        return 0;

        if ((s + target) % 2 != 0)
        return 0; // p cant be odd !!!
        
        vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
        dp[0][0] = 1;
        
        for(int j = 1; j<s+1; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=s; j++){
                int take = 0;
                if(nums[i-1] <= j){
                    take = dp[i-1][j-nums[i-1]];
                }
                int nT = dp[i-1][j];
                
                dp[i][j] = take + nT;
            }
        }
        
        // for(int i = 0; i<=s; i++){
        //     if(dp[n][i]){
        //         int x = abs(i-s);
        //         int df = abs(x-i);
                
        //         if(df == target)
        //         {
        //             cnt += dp[n][i];
        //             dp[n][i] = 0;
        //             dp[n][x] = 0;
        //         }
        //     }
        // }
        
        int positive = (target + s)/2;
        
        // return cnt;
        return dp[n][positive];
    }
};
