class Trienode{
    public:
        char data;
        Trienode* children[26];
        int childCount;
        bool isterminal;

        Trienode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            childCount = 0;
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
                root -> childCount += 1;
            }

            insertutil(root -> children[index] , word , idx + 1);
        }

        void insert(string word){
            insertutil(root , word , 0);
        }

        void get_ansutil(Trienode* root , string word , string& s){
            
            for(int i = 0; i<word.size() ; i++ ){
                if(root -> isterminal)break;
                
                if(root -> childCount != 1)break;

                char ch = word[i];

                int idx = ch - 'a';

                s += ch;

                root = root -> children[idx];

                
            }
        }


        void get_ans(string word , string& s){
             get_ansutil(root , word , s);
        }

               
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        Trie t ;
        for(int i =0 ;i<strs.size() ; i++){
            t.insert(strs[i]);
        }
        string ans = "";
        t.get_ans(strs[0] ,  ans);

        return ans;
    }
};