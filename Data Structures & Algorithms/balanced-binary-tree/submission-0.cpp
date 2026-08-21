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

    int hgtCalc(TreeNode* root, int &diff){
        if(root == NULL)
        return 0;

        int lH = hgtCalc(root -> left, diff);
        int rH = hgtCalc(root -> right, diff);
        
        diff = max(diff, abs(lH-rH));

        return 1+max(lH, rH);
    }

    bool isBalanced(TreeNode* root) {
        int heightDifference = 0;
        hgtCalc(root, heightDifference);

        if(heightDifference > 1)
        return false;

        return true;
    }
};
