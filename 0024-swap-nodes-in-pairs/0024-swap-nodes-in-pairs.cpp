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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head -> next == NULL)return head;

        ListNode* prev = new ListNode(-1);

        prev -> next = head;
        ListNode* curr = head;
        ListNode* agla = curr -> next;

        ListNode* ans = agla;

        while(agla){
            ListNode* temp = agla -> next;
            prev -> next = agla;
            agla -> next = curr;
            curr -> next = temp;
            prev = curr;
            curr = curr -> next;
            if(curr)
                agla = curr -> next;
            else break;
        }

        return ans;
    }
};