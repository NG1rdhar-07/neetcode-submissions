class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 0 || n == 1)
        return true;
        
        int l = 0;
        int r = n-1;


        transform(s.begin(), s.end(), s.begin(), ::tolower);

        while(l <= r){
            // while(l < n && l<= r && !(!isalpha(s[l]) && !isdigit(s[l])))
            // l++;

            // while(r >= 0 && l<= r && !(!isalpha(s[r]) && !isdigit(s[r])))
            // r--;

            // if(l <= r && (isalpha(s[l]) || isdigit(s[l])) && (isalpha(s[r] || isdigit(s[r]))) && s[l] != s[r])
            // return false;

            // l++;
            // r--;

            while(l < r && !isalnum(s[l]))
                l++;

            while(l < r && !isalnum(s[r]))
                r--;

            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
