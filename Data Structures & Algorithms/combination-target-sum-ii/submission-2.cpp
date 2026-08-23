class Solution {
public:

    void helper(vector<vector<int>> &soln, vector<int> &candidates, int required, int index, vector<int> &op){ 
        
        if(required == 0)
        {
            soln.push_back(op);
            return;
        }

        if(index >= candidates.size() || required < 0)
        return;

        // if(candidates[index] > required)
        // return;

        // if(index > 0 && candidates[index] == candidates[index-1])
        // {
        //     helper(soln, candidates, required, index+1, op);
        //     return;
        // }

        op.push_back(candidates[index]);
        helper(soln, candidates, required-candidates[index], index+1, op);
        op.pop_back();

        while(index+1 < candidates.size() &&
          candidates[index] == candidates[index+1])
        {
            index++;
        }

        helper(soln, candidates, required, index+1, op);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> soln;
        vector<int> op;

        helper(soln, candidates, target, 0, op);
        return soln;
    }
};
