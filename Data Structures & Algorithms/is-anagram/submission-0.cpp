class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chr1(26, 0);
        vector<int> chr2(26, 0);
        
        int sLen = s.length();
        int tLen = t.length();

        if(sLen != tLen)
        return false;

        for(int i = 0; i<sLen; i++){
            chr1[s[i] - 'a']++;
            chr2[t[i] - 'a']++;
        }

        for(int i = 0; i<26; i++){
            if(chr1[i] != chr2[i])
            return false;
        }

        return true;
    }
};
