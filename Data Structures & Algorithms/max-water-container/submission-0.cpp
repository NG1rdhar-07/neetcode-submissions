class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lMax = 0;
        int rMax = 0;
        int aMax = 0;

        int l = 0; 
        int n = heights.size();
        int r = n-1;

        while(l < r){
            int len = r-l;
            int minV = min(heights[l], heights[r]);
            int crntArea = len*minV;

            aMax = max(aMax, crntArea);

            if(heights[l] < heights[r])
            l++;

            else if(heights[l] >= heights[r])
            r--;
        }

        return aMax;
    }
};
