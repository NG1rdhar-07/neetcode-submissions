class Solution {
public:

    void helper(vector<vector<int>> &soln, vector<int> &ip, vector<int> &op, int index){

       if(index == ip.size()){
            soln.push_back(op);
            return;
       }

        op.push_back(ip[index]);
        helper(soln, ip, op, index+1);
        op.pop_back();
        helper(soln, ip, op, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> soln;
        //vector<int> inp;
        vector<int> op;

        helper(soln, nums, op, 0);

        return soln;
    }
};
