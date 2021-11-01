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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        
        queue<TreeNode*> Q;
        if(root == NULL)
            return ans;
        
        Q.push(root);
        while(!Q.empty()){
            int sz = Q.size();
            double sum = 0.0;
            for(int i = 1; i <= sz; i++){
                sum += Q.front()->val;
                if(Q.front()->left != NULL){
                    Q.push(Q.front()->left);
                }
                if(Q.front()->right != NULL){
                    Q.push(Q.front()->right);
                }
                Q.pop();
            }
            ans.push_back(sum/(double)sz);
        }
        return ans;
    }
};