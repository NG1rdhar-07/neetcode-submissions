class Solution {
public:

    bool isValid(string s){
        int oB = 0;
        int cB = 0;

        for(auto i : s){
            if(cB > oB)
            return false;

            if(i == '(')
            oB++;

            else if(i == ')')
            cB++;
        }

        if(oB != cB)
        return false;

        return true;
    }

    void helper(vector<string> &soln, int n, int ind, string op){
        // if(ind == n && isValid(op)){
        //     soln.push_back(op);
        //     return;
        // }

        if(ind == 2*n){
            if(isValid(op))
            soln.push_back(op);
            
            return;
        }

        op += '(';
        helper(soln, n, ind+1, op);
        op.pop_back();

        op += ')';
        helper(soln, n, ind+1, op);
        op.pop_back();

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        string op = "";

        helper(soln, n, 0, op);

        return soln;
    }
};
