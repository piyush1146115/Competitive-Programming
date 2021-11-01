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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        int level = 0;
        
        while(!Q.empty()){
            vector<int> temp;
            int sz = Q.size();
            while(sz--){
                temp.push_back(Q.front()->val);
                if(Q.front()->left != NULL)
                    Q.push(Q.front()->left);
                if(Q.front()->right != NULL)
                    Q.push(Q.front()->right);
                Q.pop();
            }
            
           if(level%2 == 1){
               reverse(temp.begin(), temp.end());
           }
            ans.push_back(temp);
            
            level++;
        }
        return ans;
    }
};