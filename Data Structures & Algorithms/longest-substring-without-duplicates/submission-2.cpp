class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[128];
        fill(freq, freq + 128, -1);

        int n = s.length();
        int maxL = 0;
        int j = 0;

        // freq[s[0] - 'a'] = 0;

        for(int i = 0; i<n; i++){
            if(freq[s[i]] >= j)
            j = freq[s[i]] + 1;

            freq[s[i]] = i;
            maxL = max(maxL, i-j+1);
        }

        return maxL;
    }
};
