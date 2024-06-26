/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return false;
        ListNode *slowPtr = head, *fastPtr = head;
        while(fastPtr->next!=NULL && fastPtr->next->next!=NULL){

            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
            
            if(slowPtr == fastPtr)return true;
        }
        return false;
    }
};