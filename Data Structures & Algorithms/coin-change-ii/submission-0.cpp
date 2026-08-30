class Solution {
public:

    int solver(int amount, vector<int>& coins, int n, int i, vector<vector<int>> &dp){
        if(amount == 0)
        return 1;

        if(i == n)
        return 0;

        if(dp[i][amount] != -1)
        return dp[i][amount];

        if(amount < coins[i])
        return dp[i][amount] = solver(amount, coins, n, i+1, dp);

        int take = solver(amount - coins[i], coins, n, i, dp);
        int notTake = solver(amount, coins, n, i+1, dp);

        return dp[i][amount] = notTake + take;
    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // for(int i = 1; i<=n; i++)
        // dp[0][i] = INT_MAX-1;
        
        return solver(amount, coins, n, 0, dp);
    }
};
