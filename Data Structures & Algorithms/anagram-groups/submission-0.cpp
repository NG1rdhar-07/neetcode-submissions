class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> preComp(n, vector<int>(26, 0));

        for(int i = 0; i<n; i++){
            int l = strs[i].length();

            for(int j = 0; j<l; j++){
                preComp[i][strs[i][j] - 'a']++;
            }
        }
        vector<vector<string>> finalSoln;
        vector<int> visited(n, 0);

        for(int i = 0; i<n; i++){
            if(visited[i])
            continue;
            
            vector<string> temp;
            temp.push_back(strs[i]);
            visited[i] = 1;

            for(int j = i+1; j<n; j++){
                if(!visited[j] && preComp[i] == preComp[j]){
                    temp.push_back(strs[j]);
                    visited[j] = 1;
                }
            }

            finalSoln.push_back(temp);
        }

        return finalSoln;
    }
};
