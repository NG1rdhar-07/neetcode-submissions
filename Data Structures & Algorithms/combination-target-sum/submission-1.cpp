class Solution {
public:

    void helper(int required, int index, vector<int> &nums, vector<vector<int>> &soln, vector<int> &op){
        if(index >= nums.size() || required < 0)
        return;

        if(required == 0)
        {
            soln.push_back(op);
            return;
        }

        op.push_back(nums[index]);
        helper(required-nums[index], index, nums, soln, op);

        op.pop_back();
        helper(required, index+1, nums, soln, op);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> soln;
        vector<int> op;

        helper(target, 0, nums, soln, op);
        return soln;
    }
};
