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

    void get_string(TreeNode* root , string& out){
        if(!root){
            out += "N,";
            return;
        }
        out += to_string(root -> val) + ',';
        get_string(root -> left , out);
        get_string(root -> right , out);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string out;
        get_string(root , out);
        return out;
    }

    TreeNode* build(vector<string>& pre , int& idx){
        if(idx >= pre.size())return NULL;

        string s = pre[idx++];

        if(s == "N")return NULL;

        TreeNode* root = new TreeNode(stoi(s));

        root -> left = build(pre , idx);
        root -> right = build(pre , idx);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;

        vector<string> pre;

        string temp = "";

        for(int i=0;i< data.size(); i++){
            char ch = data[i];

            if(ch == ','){
                pre.push_back(temp);
                temp.clear();
            }else temp += ch;
        }

        int idx = 0;

        return build(pre , idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));