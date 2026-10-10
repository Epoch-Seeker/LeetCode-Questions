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
class BSTIterator {
public:
    vector<int> ans;
    int i;
    BSTIterator(TreeNode* root) {
        inordertraversel(root);
        i = -1;
    }

    void inordertraversel(TreeNode* root){
        if(root -> left)inordertraversel(root -> left);
        ans.push_back(root -> val);
        if(root -> right)inordertraversel(root -> right);
    }
    
    int next() {
        return ans[++i];
    }
    
    bool hasNext() {
        return i+1 < ans.size();
    }
};

/**
 * Your BSTIter ator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */