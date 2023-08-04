//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        
    void insertAtBottom(stack<int>&St,int element){
        if(St.empty()){
            St.push(element);
            return;
        }
        int ele = St.top();
        St.pop();
        
        insertAtBottom(St,element);
        St.push(ele);
    }

    void rev(stack<int>&St){
        if(St.size() <= 1)return;
        
        int element = St.top();
        St.pop();
        rev(St);
        insertAtBottom(St,element);
    }

    void Reverse(stack<int> &St) {
      rev(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends