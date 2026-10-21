class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        vector<int> soln;

        for(int i : nums){
            mp[i]++;
        }

        for(auto [x,y] : mp){
            pq.push({y, x});
        }

        while(k > 0){
            soln.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return soln;
    }
};
