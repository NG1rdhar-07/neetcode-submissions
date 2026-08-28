class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) //MISSED
        return nums[0];

        // int maxM = 0;
        // vector<int> dp(n);

        int p2 = nums[0];
        // dp[1] = nums[1];
        int p1 = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++){
            int pick = p2 + nums[i];
            int notPick = p1;
            int a = max(pick, notPick);

            p2 = p1;
            p1 = a;
            // maxM = max(maxM, dp[i]);
        }

        // return maxM;
        return p1;
    }
};
