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
    int cnt = 0;
    
    void traverse(TreeNode* root, int mx){
        if(root == NULL)
            return;
        
        if(root->val >= mx)
            cnt++;
        traverse(root->left, max(mx, root->val));
        traverse(root->right, max(mx, root->val));
    }
    
    int goodNodes(TreeNode* root) {
        if (root != NULL)
            traverse(root, root->val);
        
        return cnt;
    }
};