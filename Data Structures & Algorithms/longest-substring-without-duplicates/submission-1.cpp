class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int l = 0; 
        int r = 0;
        int maxL = 0;

        unordered_map<char, int> mp;

        // while(l<=r && r < n && l < n){
        //     if(mp.find(s[r]) != mp.end()){
        //         l = mp[s[r]] + 1;
        //         mp.erase(s[r]);
        //     }

        //     if(mp.find(s[r]) == mp.end()){
        //         mp[s[r]] = r;
        //         r++;
        //     }

        //     maxL = max(maxL, r-l);
        // }

        while(r < n){
            if(mp.find(s[r]) != mp.end())
            l = max(l, mp[s[r]]+1);

            mp[s[r]] = r;
            maxL = max(maxL, r-l+1);
            r++;
        }

        return maxL;
    }
};
