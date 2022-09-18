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
    vector<TreeNode*> makeTrees(int lo, int hi){
        if(lo > hi ){
        return {NULL};
      }
        
        vector<TreeNode*> left, right, BSTs;
        
        for(int i = lo; i <= hi; i++){
            left = makeTrees(lo, i-1);
            right = makeTrees(i+1, hi);
            
            for(auto l : left){
                for(auto r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    BSTs.push_back(root);
                }
            }
        }
        
        return BSTs;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return makeTrees(1, n);
    }
};