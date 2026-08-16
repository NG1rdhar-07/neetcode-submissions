class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        
        while(l <= h){
            int mid = l + (h-l)/2;

            if(mid == h)
            break;

            if(nums[mid] < nums[h]) // mid itself can be smaller, so h = mid !!
            h = mid;
            else if(nums[mid] > nums[h]) // agar mid > h toh main mid kyun hi lunga, that is why mid + 1...smaller soln always lies ahead of mid !!
            l = mid+1;
        }

        return nums[l];
    }
};
