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
        map<int , TreeNode*> mp;
        map<int , int> parent;
        TreeNode* ans = NULL;

        for(auto v : descriptions){
            parent[v[1]] = v[0];
            if(!parent.count(v[0]))parent[v[0]] = 0;
            if(mp.count(v[0])){
                auto par = mp[v[0]];
                if(mp.count(v[1])){
                    auto ch = mp[v[1]];
                    if(v[2]){
                        par -> left = ch;
                    }else{
                        par -> right = ch;
                    }
                }else{
                    TreeNode* ch = new TreeNode(v[1]);
                    mp[v[1]] = ch;
                    if(v[2]){
                        par -> left = ch;
                    }else{
                        par -> right = ch;
                    }
                }
            }else{
                TreeNode* par = new TreeNode(v[0]);
                mp[v[0]] = par;
                if(mp.count(v[1])){
                    auto ch = mp[v[1]];
                    if(v[2]){
                        par -> left = ch;
                    }else{
                        par -> right = ch;
                    }
                }else{
                    TreeNode* ch = new TreeNode(v[1]);
                    mp[v[1]] = ch;
                    if(v[2]){
                        par -> left = ch;
                    }else{
                        par -> right = ch;
                    }
                }

            }
        }

        for(auto it : parent){
            if(it.second == 0)ans = mp[it.first];
        }

        return ans;
        
    }
};