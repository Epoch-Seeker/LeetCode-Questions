/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return  "";
        string temp = to_string(root -> val) + '#';
        string left = serialize(root -> left);
        string right = serialize(root -> right);
        return temp + left + right;
    }

    TreeNode* build(vector<int>& preorder , int& i , int a , int b){
        if(i == preorder.size())return NULL;

        int val = preorder[i];

        if(val <= a || val >= b)return NULL;
        i++;
        TreeNode* ans = new TreeNode(val);

        ans -> left = build(preorder , i, a , val);
        ans -> right = build(preorder , i, val , b);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
         
        vector<int> preorder;
        string temp;
        for(int i=0;i< data.size(); i++){
            if(data[i] != '#')
                temp += data[i];
            else{
                preorder.push_back(stoi(temp));
                temp.clear();
            }
        }
        // for(int i : preorder)cout<<i<<" ";
        int i = 0;
        return build(preorder , i ,-1 , INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;