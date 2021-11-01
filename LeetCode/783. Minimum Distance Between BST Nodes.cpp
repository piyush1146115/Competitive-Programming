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
    int prev = -1, ans = INT_MAX;
    
    int minDiffInBST(TreeNode* root) {
        if(root ==  NULL){
            return ans;
        }
        if(root->left != NULL)
            ans = min(ans, minDiffInBST(root->left));
        
        if(prev != -1){
            ans = min(ans, abs(root->val - prev));
        }
        
        prev = root->val;
        
        if(root->right != NULL)
            ans = min(ans, minDiffInBST(root->right));
        
        return ans;
    }
};