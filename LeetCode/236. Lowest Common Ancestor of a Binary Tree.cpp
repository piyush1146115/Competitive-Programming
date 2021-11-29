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
    vector<vector<TreeNode*> > path;
    
    void traverse(TreeNode* root, TreeNode* p, vector<TreeNode*> &v){
        if(root == NULL)
            return;
        
        v.push_back(root);
        if(root == p){
            path.push_back(v);
            return;
        }
            
            
        traverse(root->left,p,v);
        traverse(root->right,p,v);
        
        v.pop_back();
        
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v;
        
        if(root == NULL)
            return root;
        
        traverse(root,p, v);
        v.clear();
        
        traverse(root,q,v);
        
        int mn = min(path[0].size(), path[1].size());
        
        TreeNode* ans;
        ans = path[0][0];
        
        // cout << path.size() << endl;
        
        for(int i = 0; i < mn; i++){
//             cout << path[0][i]->val << endl;
//             cout << path[1][i]->val << endl;
            
            if(path[0][i] != path[1][i])
                break;
            
            ans = path[0][i];
        }
        
        return ans;
    }
};