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
class Trie {
public:
    Trienode* root;
    Trie() {
        root = new Trienode('q');
        return ;
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
    
    void insert(string word) {
        insertutil(root , word , 0);
    }

    bool searchutil(Trienode* root , string word , int idx){
        if(idx == word.size()){
            if(root -> isterminal == true)return true;
            return false;
        }

        char ch = word[idx];

        int index = ch - 'a';
        
        // char not present
        if(root -> children[index] == NULL){
            return false;
        }

        return searchutil(root -> children[index] , word , idx + 1);
    }
    
    bool search(string word) {
        return searchutil(root , word , 0);
    }

    bool searchWithutil(Trienode* root , string word , int idx){
        if(idx == word.size()){
            return true;
        }

        char ch = word[idx];

        int index = ch - 'a';
        
        // char not present
        if(root -> children[index] == NULL){
            return false;
        }

        return searchWithutil(root -> children[index] , word , idx + 1);
    }
    
    bool startsWith(string prefix) {
        return searchWithutil(root , prefix , 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */