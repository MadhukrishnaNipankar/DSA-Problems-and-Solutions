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
    //using stack     
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp!=NULL){
            int value = st.top();
            st.pop();
            temp->val = value;
            temp=temp->next;
        }
        
        return head;
    }
};