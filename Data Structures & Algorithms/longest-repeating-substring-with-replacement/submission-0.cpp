class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0;  
        int maxFreq = 0;
        int n = s.length();
        int soln = 0;

        // replacable chars : (r-l+1)-maxFreq

        for(int r = 0; r<n; r++){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while((r-l+1)-maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }

            soln = max(soln, r-l+1);
        }

        return soln;
    }
};
