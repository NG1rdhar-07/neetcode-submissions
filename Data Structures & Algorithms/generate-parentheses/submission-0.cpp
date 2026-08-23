class Solution {
public:

    // bool isValid(string prn){
    //     stack<char> st;

    //     for(auto it : prn){
    //         if(st.empty()){
    //             if(it == ')')
    //             return false;
    //         }
               
    //         if(it == '(')
    //         st.push(it);

    //         else{
    //             //if(it == ')')
    //             st.pop();
    //         }
    //     }

    //     return st.empty();
    // }


    // void helper(string &temp, vector<string> &soln, int n, int ind){
    void helper(string &temp, vector<string> &soln, int n, int open, int close){
        if(temp.size() == 2*n)
        {
            // if(isValid(temp))
            soln.push_back(temp);
            return;
        }

        if(open < n)
        {
            temp.push_back('(');
        helper(temp, soln, n, open+1, close);
        temp.pop_back();
        }

        if(open > close)
        {
            temp.push_back(')');
        helper(temp, soln, n, open, close+1);
        temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        string temp = "";

        helper(temp, soln, n, 0, 0);
        return soln;
    }
};
