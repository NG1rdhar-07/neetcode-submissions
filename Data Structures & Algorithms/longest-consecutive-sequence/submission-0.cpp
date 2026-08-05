class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = muns.size();

        unordered_set<int> st;
        int soln = 0;

        for(int i : nums){
            st.insert(i);
        }

        for(int it : st){
        if(!st.count(it-1)){
                int crnt = it;
                int l = 1;

                while(st.count(crnt + 1)){
                    crnt++;
                    l++;
                }

                soln = max(soln, l);
            }
        }

        return soln;
    }
};
