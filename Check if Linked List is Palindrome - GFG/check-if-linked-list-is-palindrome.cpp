//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
            // if only 1 node, then it is palindrome
            if(head->next == NULL)return true; 
            
            Node *temp1 = head, *temp2 = head;
            // temp1 is slowPtr and temp2 is fastPtr
            while(temp2->next!= NULL && temp2->next->next!=NULL){
                temp1=temp1->next;
                temp2=temp2->next->next;
            }
            
            // Now temp1 is the middle of the Linked List
            // reverse the linkedList from middle+1 node to end
            Node *temp = NULL;
            Node *current = temp1->next;
            Node *forward;
            
            while(current!=NULL){
                forward = current->next;
                current->next = temp;
                temp = current;
                current = forward;
            }
            temp1->next = temp;
            
            // now check if the left half of the linkedlist is equal to right half
            temp2 = temp1->next;
            temp1 = head;
            
            while(temp2!=NULL){
                if(temp1->data!=temp2->data)return false;
                temp1=temp1->next;
                temp2=temp2->next;
            }

            return true;
            
            
            /*
            1 2 3 3 2 1
                .   .
                
            
            1 2 3 2 1
                .   .
            */
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends