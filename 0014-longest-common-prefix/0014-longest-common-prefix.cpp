class Trienode{
    public:
        char data;
        Trienode* children[26];
        bool isterminal;

        Trienode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isterminal = false;
        }
};

class Trie{
    public:
        Trienode* root;
        Trie(){
            root = new Trienode('\0');
        }

        void insertutil(Trienode* root , string word , int idx){
            if(idx == word.size()){
                root -> isterminal = true;
                return;
            }

            char ch = word[idx];

            int index = ch - 'a';

            // char not present
            if(root -> children[index] == NULL){
                root -> children[index] = new Trienode(ch);
            }

            insertutil(root -> children[index] , word , idx + 1);
        }

        void insert(string word){
            insertutil(root , word , 0);
        }

        void get_ansutil(Trienode* root , string& s){
            int child_count = 0;

            Trienode* child;

            for(int i = 0 ;i< 26 ; i++){
                if(root -> children[i]){
                    child = root -> children[i];
                    child_count++;
                }
            }

            if(child_count != 1)return;

            s += child -> data;

            if(child -> isterminal == true)return;

            get_ansutil(child , s);
        }


        void get_ans(string& s){
             get_ansutil(root , s);
        }

               
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(auto a : strs){
            if(a == "")return "";
        }
        Trie t ;
        for(int i =0 ;i<strs.size() ; i++){
            t.insert(strs[i]);
        }
        string ans = "";
        t.get_ans(ans);

        return ans;
    }
};