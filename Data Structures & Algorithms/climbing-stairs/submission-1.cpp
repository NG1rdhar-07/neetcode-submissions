class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1);

        // dp[0] = 1;
        // dp[1] = 1;

        int p2 = 1;
        int p1 = 1;

        for(int i = 2; i<=n; i++){
            int ans = p1 + p2;
            p2 = p1;
            p1 = ans;
        }

        return p1;
    }
};
