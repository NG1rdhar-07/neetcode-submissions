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

    int heightCalc(TreeNode* root, int &diam){
        if(root == NULL)
        return 0;

        int lH = heightCalc(root -> left, diam);
        int rH = heightCalc(root -> right, diam);

        diam = max(diam, lH+rH);

        return 1 + max(lH, rH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightCalc(root, diameter);

        return diameter;
    }
};
