class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int h = rows*cols-1;

        while(l <= h){
            int mid = l+(h-l)/2;
            // int rV = mid/(cols-1);
            // int cV = mid/(rows-1);

            int rV = mid/cols;
            int cV = mid%cols;
            
            if(matrix[rV][cV] == target){
                return true;
            }
            else if(matrix[rV][cV] > target)
                h = mid-1;
            else
                l = mid+1;
        }

        return false;
    }
};
