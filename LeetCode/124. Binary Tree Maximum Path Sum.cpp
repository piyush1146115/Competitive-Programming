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
    int maxSum = INT_MIN;
    
    int pathSum(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int leftSum = max(0,pathSum(root->left));
        int rightSum = max(0, pathSum(root->right));
        
        int curSum = root->val + leftSum + rightSum;
        
        maxSum = max(maxSum, curSum);
        
        int retSum =  (root->val + max(leftSum, rightSum));
        
        return retSum;
    }
    
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        
        return maxSum;
    }
};