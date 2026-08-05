class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = height[0];
        int rMax = height[n-1];
        int water = 0;

        int l = 0;
        int r = n-1;

        while(l < r){
            if(height[l] > height[r])
            {
                r--;
                if(rMax < height[r])
                rMax = height[r];

                water += rMax - height[r];
            }

            else{
                l++;
                if(lMax < height[l])
                lMax = height[l];

                water += lMax - height[l];
            }
        }

        return water;
    }
};
