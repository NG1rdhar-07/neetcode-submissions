class Solution {
public:

    void helper(vector<vector<int>> &soln, vector<int> &candidates, int required, int index, vector<int> &op){ // unordered_map<vector<int>, int> mp; INVALID !!
        if(required < 0)
        return;

        // if(index > 0 && candidates[index] == candidates[index-1])
        // helper(soln, candidates, required, index+1, op, candidates[index]);

        if(required == 0) // && mp.find(op) == mp.end()
        {
            soln.push_back(op);
            // mp[op]++;
            return;
        }

        // op.push_back(candidates[index]);
        // helper(soln, candidates, required-candidates[index], index+1, op, candidates[index]);

        // op.pop_back();

        for(int i = index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])
            continue;

            op.push_back(candidates[i]);
            helper(soln, candidates, required-candidates[i], i+1, op);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> soln;
        // unordered_map<vector<int>, int> mp;
        vector<int> op;

        helper(soln, candidates, target, 0, op);
        return soln;
    }
};
