class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n-1;

        int mA = 0;

        while(l < r){
            mA = max(mA, (r-l) * min(heights[l], heights[r]));
            
            if(heights[l] > heights[r])
            r--;

            else
            l++;
        }

        return mA;
    }
};
