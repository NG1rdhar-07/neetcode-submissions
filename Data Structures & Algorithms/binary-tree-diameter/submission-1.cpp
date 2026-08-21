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
    int hgtCalc(TreeNode *root, int &diam){
        if(root == NULL)
        return 0;

        int lH = hgtCalc(root -> left, diam);
        int rH = hgtCalc(root -> right, diam);

        diam = max(diam, lH+rH);

        return 1+max(lH, rH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        hgtCalc(root, d);

        return d;
    }
};
