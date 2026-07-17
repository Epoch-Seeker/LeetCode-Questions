class Node{
    public:
        int freq;
        unordered_set<string> keys;
        Node* next;
        Node* prev;

        Node(int d){
            this-> freq = d;
            this-> prev = NULL;
            this-> next = NULL;
        } 
};
class AllOne {
public:
    unordered_map<string , Node*> mp;
    Node* head;
    Node* tail;
    void insertAfter(Node* node , Node* newnode){
        newnode -> next = node -> next;
        node -> next = newnode;
        newnode -> prev = node;
        newnode -> next -> prev = newnode;
    }
    void removeNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        delete node;
    }
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    void inc(string key) {
        // new key
        if(!mp.count(key)){
            // first key
            if(head -> next != tail && head -> next -> freq == 1){
                head -> next -> keys.insert(key);
            }else{
            
                Node* temp = new Node(1);
                temp -> keys.insert(key);
                insertAfter(head , temp);
            }
            mp[key] = head->next;
            return;
        }

        Node* node = mp[key];
        
        // next freq already exit
        if(node -> freq + 1 == node -> next -> freq){
            node -> next -> keys.insert(key);
        }else{
            Node* temp = new Node(node -> freq + 1);
            temp -> keys.insert(key);
            insertAfter(node , temp);
        }
        mp[key] = node -> next;

        node -> keys.erase(key);
        if(node -> keys.empty())removeNode(node);
    }
    
    void dec(string key) {
        Node* node = mp[key];

        if(node -> freq == 1){
            node -> keys.erase(key);
            if(node -> keys.empty()){
                node -> prev -> next = node -> next;
                node -> next -> prev = node -> prev;
                delete node;
            }
            mp.erase(key);
            return;
        }

        // the dec freq node exit
        if(node -> freq -1 == node -> prev -> freq){
            node -> prev -> keys.insert(key);
        }else{
            Node* temp = new Node(node -> freq - 1);
            temp -> keys.insert(key);
            insertAfter(node -> prev , temp);
        }
        mp[key] = node -> prev;

        node -> keys.erase(key);
        if(node -> keys.empty())removeNode(node);
    }
    
    string getMaxKey() {
        if(tail -> prev == head)return "";
        return *(tail -> prev -> keys.begin());
    }
    
    string getMinKey() {
        if(head -> next == tail)return "";
        return *(head -> next -> keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */