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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> Q;
        
        TreeNode* marker = NULL;
        
        Q.push(root);
        Q.push(marker);
        
        int level = 1, sum = 0, mx = INT_MIN, mxlevel = 1;
        
        while(Q.size() > 1){
            TreeNode* node = Q.front();
            Q.pop();
          //  cout << mx << " " << sum << endl;
            
            if(node == marker){
                if(sum > mx){
            //        cout << mx << " " << sum << endl;
                    mxlevel = level;
                    mx = sum;
                    
                }
                sum = 0;
                level++;
                Q.push(marker);
            }else{
                sum += node->val;
                
                if(node->left != NULL)
                    Q.push(node->left);
                if(node->right != NULL)
                    Q.push(node->right);
            }
        }
        
         if(sum > mx){
                    // cout << mx << " " << sum << endl;
                    mxlevel = level;
                    mx = sum;
                }
        
        return mxlevel;
    }
};