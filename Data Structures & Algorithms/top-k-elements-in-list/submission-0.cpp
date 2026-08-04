class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> vp(mp.begin(), mp.end());

        // vp

        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            if(a.second == b.second)
            return a.first < b.first;

            return a.second > b.second;
        });

        vector<int> tmp;

        for(int i = 0; i<k; i++){
            tmp.push_back(vp[i].first);
        }

        return tmp;
    }
};
