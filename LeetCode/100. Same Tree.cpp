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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
//         if(p  == NULL && q == NULL)
//             return true;
//         if(p == NULL || q == NULL)
//             return false;
//         if(p -> val != q -> val)
//             return false;
        
//         return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -            > right);
        
        queue<TreeNode*> Q;
        
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        Q.push(p);
        Q.push(q);
        
        while(!Q.empty()){
            TreeNode* first = Q.front();
            Q.pop();
            TreeNode* second = Q.front();
            Q.pop();
            
            if(first == NULL && second == NULL)
                continue;
            if(first == NULL || second == NULL)
                return false;
            if(first -> val != second -> val)
                return false;
            
            Q.push(first -> left);
            Q.push(second -> left);
            Q.push(first -> right);
            Q.push(second -> right);
            
        }
        
        return true;
    }
};
