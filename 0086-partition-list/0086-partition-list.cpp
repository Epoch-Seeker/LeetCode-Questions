/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)return head;
        ListNode* temp_head = new ListNode(-1);
        ListNode* temp_tail = temp_head;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            if(curr -> val >= x){
                ListNode* temp = curr -> next;
                if(prev){
                    temp_tail -> next = curr;
                    prev -> next = curr -> next;
                    curr -> next = NULL;
                    temp_tail = curr;
                }else {
                    temp_tail -> next = curr;
                    head = head -> next;
                    curr -> next = NULL;
                    temp_tail = curr;
                }
                curr = temp;
            }else {
                prev = curr;
                curr = curr -> next;
                
            }
        }

        if(prev && temp_head){
            prev -> next = temp_head -> next;
            return head;
        }else if(prev){
            return head;
        }else return temp_head -> next;
            
        
    }
};