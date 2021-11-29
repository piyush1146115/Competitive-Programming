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
//     map<pair<TreeNode*, int>, int> mp;
//     int fun(TreeNode* root, int status){
//         if(root == NULL)
//             return 0;
        
//         if(mp[{root,status}] != 0)
//             return mp[{root,status}];
        
        
//         int ret1, ret2;
        
//         if(status == 0){
//             ret1 = root->val + fun(root->left, 1) + fun(root->right, 1);
//             ret2 = fun(root->left,0) + fun(root->right,0);
//         }
//         else{
//             ret1 = 0;
//             ret2 = fun(root->left,0) + fun(root->right,0);
//         }
        
//         mp[{root,status}] = max(ret1, ret2);
//         return max(ret1, ret2);
//     }
    
//         map<TreeNode*, int> mp;
//     int fun(TreeNode* root){
//         if(root == NULL)
//             return 0;
        
//         if(mp[root] != 0)
//             return mp[root];
        
        
//         int ret = 0;
        
//         if(root->left != NULL){
//             ret += fun(root->left->left) + fun(root->left->right);
//         }
        
//         if(root->right != NULL){
//             ret += fun(root->right->left) + fun(root->right->right);
//         }
        
        
//         int ans = max(ret+root->val, fun(root->left) + fun(root->right));
//         mp[root] = ans;
        
//         return ans;
//     }
    
    
    pair<int,int> fun(TreeNode* root){
        if (root == NULL){
            return {0, 0};
        }
        
        pair<int,int> left = fun(root->left);
        pair<int,int> right = fun(root->right);
        
        pair<int,int> ret;
        
        ret.first = max(left.first, left.second) + max(right.first, right.second);
        ret.second = root->val + left.first + right.first;
        
        return ret;
    }
    
    
    int rob(TreeNode* root) {
        // return fun(root);
        pair<int,int> ans = fun(root);
        
        return max(ans.first, ans.second);
        
    }
};