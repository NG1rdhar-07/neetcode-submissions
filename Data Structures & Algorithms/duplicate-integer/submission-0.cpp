class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        int s = mp.size();

        return (n != s);
    }
};