class Solution {
public:

    int getMoney(vector<int>& nums, int l, int r){
        int n = nums.size();
        vector<int> dp(n);

        // dp[0] = 0;
        // dp[1] = 0;

        dp[l] = nums[l];

        if(l + 1 <= r)
        dp[l+1] = max(nums[l], nums[l+1]);

        // for(int i = l; i<= r; i++){
        for(int i = l+2; i<= r; i++){
            int pick = dp[i-2] + nums[i];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }

        return dp[r];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        int firstTaken = getMoney(nums, 0, n-2);
        int lastTaken = getMoney(nums, 1, n-1);

        return max(firstTaken, lastTaken);
    }
};
