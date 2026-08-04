class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int n = strs.size();

        for(auto &str : strs){
            s += to_string(str.length()) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i =0;
        int n = s.length();

        while(i < n){
            int j = i;

            while(s[j] != '#')
            j++;

            int l = stoi(s.substr(i, j-i));
            j++;

            string w = s.substr(j, l);
            ans.push_back(w);

            i = j + l;
        }

        return ans;
    }
};
