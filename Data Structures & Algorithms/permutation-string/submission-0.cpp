class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2)
        return false;

        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        int l = 0;

        for(char c : s1)
        f1[c-'a']++;

        for(int r = 0; r<n2; r++){
            f2[s2[r]-'a']++;

            while(r-l+1 > n1)
            {
                f2[s2[l]-'a']--;
                l++;
            }

            if(r-l+1 == n1)
            {   
                if(f1 == f2)
                return true;
            }
        }

        return false;
    }
};
