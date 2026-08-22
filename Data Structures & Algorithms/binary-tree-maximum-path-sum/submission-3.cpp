/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // void inOT(TreeNode *root, vector<int> &vt){
    //     if(root == nullptr)
    //     return;

    //     inOT(root -> left, vt);
    //     vt.push_back(root -> val);
    //     inOT(root -> right, vt);
    // }
    int mS = INT_MIN;

    int helper(TreeNode *root){
        if(root == nullptr)
        return 0;

        int lSum = max(0, helper(root -> left));
        int rSum = max(0, helper(root -> right));

        mS = max(mS, root -> val + lSum + rSum);

        return root -> val + max(lSum, rSum);
    }

    int maxPathSum(TreeNode* root) {
        // vector<int> arr;
        // inOT(root, arr);

        // int maxS = arr[0];
        // int s = arr[0];

        // for(int i = 1; i<arr.size(); i++){
        //     s = max(0, s+arr[i]);
        //     maxS = max(maxS, s);
        // }

        // return maxS;

        int x = helper(root);
        return mS;
    }
};
