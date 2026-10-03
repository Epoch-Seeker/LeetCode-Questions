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
    ListNode* rotateRight(ListNode* head, int k) { 
        if(!head || !head -> next)return head;
        // if(k == 0)
        int len = 0;
        ListNode* temp = head;
        while(temp -> next){
            len++;
            temp = temp -> next;
        }
        len++;
        // cout<<len;
        k = k % len;
        // cout<<k;
        int t = len-k;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(t--){
            prev = curr;
            curr = curr -> next;
        }

        ListNode* ans = prev -> next;
        if(!ans)return head;
        prev -> next = NULL;
        temp -> next = head;
        return ans;
    }
};