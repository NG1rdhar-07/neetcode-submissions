class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);

        dp[0] = true;

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=i-1; j++){
                // string word = s.substr(s.begin()+j, s.begin()+i);     WRONG !!

                string word = s.substr(j, i-j); // start posn. length
                // for(auto it : wordDict){
                //     if(it == word)
                //     {
                //         if(dp[j] == true)
                //         {
                //             dp[i] = true;
                //             break;
                //         }
                //     }
                // }

                bool wordExist = false;

                for(auto it : wordDict){
                    if(it == word)
                    {
                        wordExist = true;
                        break;
                    }
                }

                if(dp[j] == true && wordExist)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
