class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ct : s)
        {
            if(ct == '(' || ct == '[' || ct == '{')
            st.push(ct);

            else{
                if(st.empty())
                return false;

                if(!st.empty() && ((st.top() == '(' && ct == ')') || (st.top() == '[' && ct == ']') || (st.top() == '{' && ct == '}')))
                st.pop();

                else
                return false;
            }
        }

        return st.empty();
    }
};
