class MinStack {
public:
    stack<pair<int, int>> st;
    // int minV = INT_MAX;

    // if(!st.empty())
    // minV = min(minV, st.top());

    MinStack() {

    }
    
    void push(int val) {
        // if(val < minV)
        // {
        //     minV = val;
        // }

        int minV = val;

        if(!st.empty())
        minV = min(val, st.top().second);
        
        st.push({val, minV});

        // else
        // st.push({val, val});
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
    }
    
    int top() {
        if(!st.empty())
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
