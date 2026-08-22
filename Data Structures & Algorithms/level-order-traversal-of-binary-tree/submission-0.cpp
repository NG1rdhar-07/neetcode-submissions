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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> soln;
        queue<TreeNode*> q;
        
        if(root == nullptr)
        return soln;

        q.push(root);
       
        // vector<int> temp;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;

            for(int i = 0; i<sz; i++){
                TreeNode *nd = q.front();
                q.pop();
                temp.push_back(nd -> val);
                
                if(nd -> left)
                q.push(nd -> left);
                if(nd -> right)
                q.push(nd -> right);
            }

            soln.push_back(temp);
        }
        
        
        // soln.push_back(temp);
        return soln;
    }
};
