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
    int preOrderIndex = 0;
    map<int, int> mp;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;   
        }
        
        return makeTree(preorder, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right)
            return NULL;
        
        int rootVal = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = makeTree(preorder, inorder, left, mp[rootVal] - 1);
        root->right = makeTree(preorder, inorder, mp[rootVal]+1, right);
        
        return root;
    }
};