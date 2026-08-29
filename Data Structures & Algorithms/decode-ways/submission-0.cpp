class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i = 1; i<=n; i++){
            if(s[i-1] >= '1' && s[i-1] <= '9')
            dp[i] += dp[i-1];

            if(i >= 2){
                int twoDN = (s[i-1]-'0') + ((s[i-2]-'0') * 10);
                
                if(twoDN >= 10 && twoDN <= 26)
                dp[i] += dp[i-2]; 
            }
        }

        return dp[n];
    }
};
