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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        set<int> st;

        for(auto v : descriptions){
            int p = v[0];
            int c = v[1];
            int isLeft = v[2];

            if(!mp.count(p))mp[p] = new TreeNode(p);

            if(!mp.count(c))mp[c] = new TreeNode(c);

            if(isLeft)mp[p] -> left = mp[c];
            else mp[p] -> right = mp[c];

            st.insert(c);

        }

        for(auto it : mp){
            if(!st.count(it.first))return it.second;
        }

        return NULL;
        
    }
};