//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // Finding the Dip Index
        int dipIndex = -1;
        for(int i=N-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                dipIndex = i;
                break;
            }
        }
        
        if(dipIndex == -1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        // finding the smallest greater number than the arr of dipIndex
        for(int i=N-1;i>dipIndex;i--){
            if(arr[i]>arr[dipIndex]){
                swap(arr[i],arr[dipIndex]);
                reverse(arr.begin()+dipIndex+1,arr.end());
                break;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends