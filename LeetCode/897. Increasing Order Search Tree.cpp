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
    TreeNode* startNode;
    TreeNode* ptr;
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return startNode;
        }
        
        TreeNode* ans;
        
        ans = increasingBST(root->left);
        
        if(startNode == NULL){
            startNode = root;
            ptr = root;
        }
        else{
            ptr->right = new TreeNode(root->val);
            ptr = ptr->right;
        }
        
        ans = increasingBST(root->right);
        
        return ans;
    }
};