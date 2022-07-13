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
    
int findMaxLen(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1+max(findMaxLen(root->left),findMaxLen(root->right));
}
    
void levelOrderRec(TreeNode* root, vector<vector<int>>& vec, int level)
{
    if(root==NULL) return;
    vec[level].push_back(root->val);
    levelOrderRec(root->left,vec,level-1);
    levelOrderRec(root->right,vec,level-1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if(root==NULL) return result;
    int count = findMaxLen(root);
    for(int i = 0; i < count; i++)
    {
        vector<int> temp;
        result.push_back(temp);
    }
    levelOrderRec(root, result, count-1);
    return result;
}
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int> > ans;
        
//         struct st {
//             TreeNode* t;
//             int level;
//         };
        
//         queue  <st> Q;
        
//         Q.push({root, 0});
        
        
//         while(!Q.empty()){
            
//             st tp = Q.front();
//             Q.pop();
            
//             if(tp.t == NULL){
//                 continue;
//             }
            
            
//             if(tp.level >= ans.size()){
//                 ans.push_back({});
//             }
                
            
//             ans[tp.level].push_back(tp.t->val);
            
//             if(tp.t->left != NULL){
//                 Q.push({tp.t->left, tp.level+1});
//             }
            
//             if(tp.t->right != NULL){
//                 Q.push({tp.t->right, tp.level+1});
//             }
//         }
        
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
};