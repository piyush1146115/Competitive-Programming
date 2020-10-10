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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode* Curr = Q.front();
            Q.pop();
            if(Curr == NULL)
                continue;
            
            TreeNode* left = Curr -> left;
            TreeNode* right = Curr -> right;
            
            Curr -> right = left;
            Curr -> left = right;
            
            Q.push(left);
            Q.push(right);
        }
        return root;
    }
};