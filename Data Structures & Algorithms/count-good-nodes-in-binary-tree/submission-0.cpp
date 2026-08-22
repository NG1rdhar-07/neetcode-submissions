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
    int goodNodes(TreeNode* root) {
        int gN = 0;
        queue<pair<TreeNode *, int>> q;

        q.push({root, root -> val});

        while(!q.empty()){
            auto[nd, maxV] = q.front();
            q.pop();

            if(nd -> val >= maxV)
            gN++;

            int newMax = max(nd -> val, maxV);
            
            if(nd -> left)
            q.push({nd -> left, newMax});
            if(nd -> right)
            q.push({nd -> right, newMax});
        }

        return gN;
    }
};
