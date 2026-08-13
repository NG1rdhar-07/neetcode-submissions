class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(n > m)
        return "";

        unordered_map<char, int> mp;
        int l = 0;
        int r= 0;
        int startInd = -1;

        int cnt = n;
        int minLen = INT_MAX;

        for(char c : t)
        mp[c]++;

        while(r < m){
            if(mp[s[r]] > 0)
            cnt--;

            mp[s[r]]--;

            while(cnt == 0){
                if(r-l+1 < minLen)
                {
                    minLen = r-l+1;
                    startInd = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                cnt++;

                l++;
            }

            r++;
        }

        if(startInd == -1)
        return "";

        else
        return s.substr(startInd, minLen);
    }
};
