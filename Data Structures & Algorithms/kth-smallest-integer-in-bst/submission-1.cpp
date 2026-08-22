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

    void helper(TreeNode* root, int &k, int &cnt, int &soln){
        if(root == nullptr)
        return;

        helper(root -> left, k, cnt, soln);
        cnt++;

        if(cnt == k)
        {
            soln = root -> val;
            return;
        }
        helper(root -> right, k, cnt, soln);
    }

    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        int s = 0;

        helper(root, k, c, s);

        return s;
    }
};
