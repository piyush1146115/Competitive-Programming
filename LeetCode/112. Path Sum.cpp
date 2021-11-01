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
    bool hasPathSum(TreeNode* root, int targetSum, int sum) {
        if(root->left == NULL && root->right == NULL){
            if(sum+root->val == targetSum)
                return true;
            
            return false;
        }
        
        bool flag = false;
        
        if(root->right != NULL)
            flag =  flag | hasPathSum(root->right, targetSum, sum+root->val);
        if(root->left != NULL)
            flag =  flag | hasPathSum(root->left, targetSum, sum+root->val);
        
        return flag;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        
        return hasPathSum(root, targetSum, 0);
    }
};