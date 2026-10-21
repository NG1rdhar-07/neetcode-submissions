class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        int x = s1.length();
        int y = s2.length();

        if(x > y)
        return false;

        for(char c : s1){
            freq1[c-'a']++;
        }

        for(int i = 0; i<x; i++){
            freq2[s2[i] - 'a']++;
        }

        bool mtc = true;

        for(int i = 0; i<26; i++){
            if(freq1[i] != freq2[i])
            {
                mtc = false;
                break;
            }
        }

        if(mtc)
        return true;

        for(int i = x; i<y; i++){
            freq2[s2[i] - 'a']++;
            freq2[s2[i-x] - 'a']--;

            mtc = true;
            for(int j = 0; j<26; j++){
                if(freq1[j] != freq2[j])
                {
                    mtc = false;
                    break;    
                }
            }

            if(mtc)
            return true;
        }

        return false;
    }
};
