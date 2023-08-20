//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:

Node* divide(int N, Node *head) {
    if (N == 1) {
        return head;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        current->next = nullptr;

        if (current->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
    }

    if (evenHead == nullptr) {
        return oddHead;
    }

    evenTail->next = oddHead;
    return evenHead;
}


    // Node* divide(int N, Node *head){
    //     if(N == 1)return head;
        
    //     Node*firstPtr = head;
    //     Node*tracker = head;
    //     Node*secPtr = head->next;
        
    //     while(secPtr!=NULL && firstPtr!=NULL){
    //         int firstData = firstPtr->data;
    //         int secondData = secPtr->data;
            
    //         // if both are odd, move 2nd ptr
    //         if(firstData%2!=0 && secondData%2!=0){
    //             secPtr=secPtr->next;
    //             tracker=tracker->next;
    //         }
    //         // if both are even, move both ptrs
    //         else if(firstData%2 == 0 && secondData%2 == 0){
    //             firstPtr=firstPtr->next;
    //             secPtr=secPtr->next;
    //             tracker=tracker->next;
    //         }
    //         // if 1st is even, 2nd is odd, move 1st
    //         else if(firstData%2 == 0 && secondData%2 !=0){
    //              firstPtr=firstPtr->next;
    //         }
    //         // if 1st is odd and 2nd is even,then do many things
    //         else if(firstData%2 != 0 && secondData%2 ==0){
    //             // main logic
    //             Node*temp = secPtr->next;
    //             secPtr->next = firstPtr;
    //             if(firstPtr == head){

    //                 head = secPtr;
    //             }

    //             tracker->next = temp;
                
    //             // move all 
    //             firstPtr=firstPtr->next;
    //             secPtr=secPtr->next;
    //             tracker=tracker->next;
    //         }
    //     }
       
       
    //   return head; 
    // }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends