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

    int height(TreeNode *root, int &maxH){
        if(root == nullptr)
        return 0;

        int lt = height(root -> left, maxH);
        int rt = height(root -> right, maxH);

        maxH = max({lt + rt, maxH});

        // if(lt == -1 || rt == -1)
        // return -1;

        // if(abs(lt - rt) > 1)
        // return -1;

        return 1 + max(lt, rt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int fV = 0;
        int x = height(root, fV);

        return fV;
    }
};
