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
    bool isIdentical(TreeNode* T1, TreeNode* T2){
        if(T1 == NULL && T2 == NULL)
            return true;
        if(T1 == NULL || T2 == NULL)
            return false;
        
        if(T1->val != T2->val)
            return false;
        
        return isIdentical(T1->left, T2->left) && isIdentical(T1->right, T2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL)
            return true;
        if(root == NULL)
            return false;
        
        if (isIdentical(root, subRoot)){
            return true;    
        }
        return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    }
};