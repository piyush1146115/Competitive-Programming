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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = -1;
        
        if(root -> left != NULL){
            left = minDepth(root->left);
        }
        
        int right = -1;
        if(root->right != NULL){
            right = minDepth(root->right);
        }
        
        if(left == -1 && right == -1){
            return 1;
        }
        else if(left == -1){
            return 1 + right;
        }
        else if(right == -1){
           return 1 + left;
        }
        
        return 1 + min(left, right);
    }
};