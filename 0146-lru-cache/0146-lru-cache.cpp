class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k , int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int cap;
    Node* start;
    Node* end;
    unordered_map<int , Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        start = new Node(-1 , -1);
        end = new Node(-1 , -1);
        start -> next = end;
        end -> prev = start;
    }

    void remove_and_insert(Node* temp){
        Node* p = temp -> prev;
        Node* n = temp -> next;
        p -> next = n;
        n -> prev = p;

        start -> next -> prev = temp;
        temp -> next = start -> next;
        start -> next = temp;
        temp -> prev = start;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        Node* temp = mp[key];
        remove_and_insert(temp);
        return temp -> val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp = mp[key];
            remove_and_insert(temp);
            temp -> val = value;
            return;
        }

        if(mp.size() == cap){
            Node* temp = end -> prev;
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            mp.erase(temp -> key);
            delete temp;
        }

        Node* temp = new Node(key , value);
        mp[key] = temp;

        start -> next -> prev = temp;
        temp -> next = start -> next;
        start -> next = temp;
        temp -> prev = start;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */