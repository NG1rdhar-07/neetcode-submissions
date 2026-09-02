class Solution {
public:

    int helper(string t1, string t2, int m, int n, vector<vector<int>> &dp){
        if(dp[m][n] != -1)
        return dp[m][n];

        if(m == 0 || n == 0)
        return 0;

        if(t1[m-1] == t2[n-1])
        return dp[m][n] = 1 + helper(t1, t2, m-1, n-1, dp);

        else{
            return dp[m][n] = max(helper(t1, t2, m-1, n, dp), helper(t1, t2, m, n-1, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.length();
        int s2 = text2.length();

        vector<vector<int>> dp(s1+1, vector<int>(s2+1, -1));
        return helper(text1, text2, s1, s2, dp);
    }
};
