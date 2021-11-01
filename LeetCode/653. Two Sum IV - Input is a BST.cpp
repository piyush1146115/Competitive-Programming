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
    vector<int> v;
    void inorder(TreeNode* root){
        if (root == NULL)
            return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
         inorder(root);    
        
        int l = 0, r = v.size() - 1;
        
        while(l < r){
            if (v[l]+v[r] == k){
                return true;
            }
            if(v[l]+v[r] > k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
    
};