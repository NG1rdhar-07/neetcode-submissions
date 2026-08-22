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
    vector<int> rightSideView(TreeNode* root) {
        //int level = 0;
        queue<TreeNode *> q;
        vector<int> soln;

        
        if(root == nullptr) // forgot this !!
        return soln;


        q.push(root);
        //level++;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i<sz; i++){
                TreeNode *nd = q.front();
                q.pop();

                
                if(i == sz-1)
                soln.push_back(nd -> val); // last node of this level !!


                if(nd -> left)
                q.push(nd -> left);
                if(nd -> right)
                q.push(nd -> right);

                // if(level == q.size())
            }

            //level++;
        }
        return soln;
    }
};
