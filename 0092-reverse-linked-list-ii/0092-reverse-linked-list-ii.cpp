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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(head == NULL || left == right)return head;
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;

        int i = 1;

        while(i < left){
            tail -> next = new ListNode(head -> val);
            tail = tail -> next;
            head = head -> next;
            i++;
        }
        
        tail -> next = new ListNode(head -> val);
        head = head -> next;
        ListNode* back = tail -> next;
        i++;

        while(i <= right){
            ListNode* temp = tail -> next;
            tail -> next = new ListNode(head -> val);
            tail -> next -> next = temp;
            head = head -> next;
            i++;
        }

        while(head){
            back -> next = new ListNode(head -> val);
            back = back -> next;
            head = head -> next;
        }

        return ans -> next;
        
    }
};