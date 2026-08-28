class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) //MISSED
        return nums[0];

        // int maxM = 0;
        vector<int> dp(n);

        dp[0] = nums[0];
        // dp[1] = nums[1];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++){
            int pick = dp[i-2] + nums[i];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);

            // maxM = max(maxM, dp[i]);
        }

        // return maxM;
        return dp[n-1];
    }
};
