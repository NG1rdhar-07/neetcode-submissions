class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sp = nums[0];
        int fp = nums[0];

        sp = nums[sp];
        fp = nums[nums[fp]];

        while(sp != fp){
            sp = nums[sp];
            fp = nums[nums[fp]];
        }

        sp = nums[0];

        while(sp != fp){
            sp = nums[sp];
            fp = nums[fp];
        }

        return sp;
    }
};
