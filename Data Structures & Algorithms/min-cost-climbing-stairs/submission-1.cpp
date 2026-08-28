class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1]; // If I am given, that I can start from 1st posn as well, I dont need to calculate cost from 0th to 1st, because woh zyada hi aayegi 1st ki cost ke comparison mein always !!

        for(int i = 2; i<n; i++){
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};
