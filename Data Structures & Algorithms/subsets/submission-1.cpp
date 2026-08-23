class Solution {
public:

    void helper(vector<vector<int>> &soln, vector<int> &ip, vector<int> &op, int index){

    //    if(index == ip.size()){
    //         soln.push_back(op);
    //         return;
    //    }

        soln.push_back(op);

        for(int i = index; i<ip.size(); i++){
            op.push_back(ip[i]);
            helper(soln, ip, op, i+1);
            op.pop_back();
        }
    
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> soln;
        //vector<int> inp;
        vector<int> op;

        helper(soln, nums, op, 0);

        return soln;
    }
};
