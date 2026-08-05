class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> soln;

        for (int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) // FORGOT 
            continue;

            int l = i + 1;
            int r = n - 1;

            // while (l < r && r>i && l<n-1) {
            while (l < r) {
                int sm = nums[i] + nums[l] + nums[r];
                if (sm == 0)
                    {
                        soln.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;

                        while(l < r && nums[l] == nums[l-1]) //FORGOT
                        l++;

                        while(l < r && nums[r] == nums[r+1]) //FORGOT
                        r--;
                    }

                else if (sm < 0)
                    l++;

                else
                    r--;
            }
        }

        return soln;
    }
};
