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
    bool solve(TreeNode* a , TreeNode* b){
        if(!a && !b)return true;
        if(!a || !b)return false;

        if(solve(a -> left , b -> right) && solve(a -> right , b -> left) && a -> val == b -> val)return true;

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;

        return solve(root -> left , root -> right);
    }
};