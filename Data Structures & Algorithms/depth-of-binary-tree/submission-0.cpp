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

    // int helper(TreeNode *nd, int &ht){
    //     if(nd == NULL)
    //     return 1;

    //     return ht;
    // }

    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;

        // int lH = helper(root -> left, lH+1);
        // int rH = helper(root -> right, rH+1);

        int lH = maxDepth(root -> left);
        int rH = maxDepth(root -> right);

        return 1+ max(lH, rH);
    }
};
