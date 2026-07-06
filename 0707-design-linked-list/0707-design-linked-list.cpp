class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};
class MyLinkedList {
public:
    Node* dummy;
    int size;
    MyLinkedList() {
        dummy = new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index <0 || index >= size)return -1;

        Node* temp = dummy -> next;
        while(index--){
            temp = temp -> next;
        }
        return temp -> data;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp -> next  = dummy -> next;
        dummy -> next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* tail = dummy;
        while(tail -> next){
            tail = tail -> next;
        }
        tail -> next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)return;

        Node* prev = dummy;

        while(index--)prev = prev ->next;

        Node* temp = new Node(val);

        temp -> next = prev -> next;
        prev -> next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)return;

        Node* prev = dummy;

        while(index--)prev = prev ->next;

        Node* del = prev -> next; 

        prev -> next = del -> next;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */