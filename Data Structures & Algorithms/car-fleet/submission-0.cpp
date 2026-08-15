class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> pT;

        for(int i = 0; i<n; i++){
            double t = (double)(target-position[i])/speed[i];
            pT.push_back({position[i], t});
        }

        sort(pT.rbegin(), pT.rend());
        stack<double> st;
        
        for(int i = 0; i<n; i++){
            if(st.empty() || st.top() < pT[i].second)
            st.push(pT[i].second);
        }
        
        return st.size();
    }
};
