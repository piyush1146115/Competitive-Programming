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
    int maxDepth(TreeNode* root) {
        int ans = Travel(root);
        return ans;
    }
    
    int Travel(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int L = 1 + Travel(root -> left);
        int R = 1 + Travel(root -> right);
        
        return max(L, R);
    }
};