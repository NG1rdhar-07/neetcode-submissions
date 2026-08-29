class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s % 2 != 0)
        return false;

        int hSum = s/2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(hSum+1));

        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<hSum+1; j++){
                if(i == 0)
                {
                    dp[i][j] = false;
                    continue;
                }

                if(j == 0){
                    dp[i][j] = true;
                    continue;
                }

                dp[0][0] = true;

                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];

                else
                dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][hSum];
    }
};
