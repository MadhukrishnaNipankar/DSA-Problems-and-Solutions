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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1)return NULL;
        
        ListNode*dummy = new ListNode(-1);
        dummy->next=head;
        ListNode*ptr1 = dummy;
        ListNode*ptr2 = dummy;
        while(n){
            ptr2=ptr2->next;
            n--;
        }
        
        while(ptr2!=NULL && ptr2->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        ptr1->next = ptr1->next->next;
        
        return dummy->next;
    }
};