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
    void path(TreeNode* root, vector<string>& ans, string s){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(s.size() > 0){
                s += "->";
            }
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        
        if(s.size() > 0){
               s += "->";
            }
        
        s += to_string(root->val);
        path(root->left, ans, s);
        path(root->right, ans, s);
        
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        path(root, ans, "");
        
        return ans;
    }
};