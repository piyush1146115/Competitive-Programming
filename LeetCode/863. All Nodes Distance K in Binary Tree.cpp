/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> vis;
    
    void findParent(TreeNode* root){
        if(root == NULL)
            return;
        
        if(root->left){
            parent[root->left] = root;
            findParent(root->left);
        }
        
        if(root->right){
            parent[root->right] = root;
            findParent(root->right);
        }
    }
    
    void dfs(TreeNode* root, int k, vector<int>&ans){
        if(root == NULL || vis.find(root)!=vis.end())
            return;
        vis.insert(root);
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        
        dfs(root->left, k-1, ans);
        dfs(root->right, k-1, ans);
        
        TreeNode* p = parent[root];
        dfs(p, k-1, ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        vector<int> ans;
        dfs(target, k, ans);
        return ans;
    }
};