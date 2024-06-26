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
    //using stack   Time: O(N) space: O(N)  
//     ListNode* reverseList(ListNode* head) {
//         stack<int>st;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             st.push(temp->val);
//             temp=temp->next;
//         }
//         temp = head;
//         while(temp!=NULL){
//             int value = st.top();
//             st.pop();
//             temp->val = value;
//             temp=temp->next;
//         }
        
//         return head;
//     }

    //just using 2 main pointers -> dummy node and next node
    //Time: O(N), Space:O(1)
     ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = NULL;
        
        while(current!=NULL){
            ListNode*front = current->next;
            current->next=previous;
            previous=current;
            current=front;
        }
         
        return previous;
     }
};