//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
   
    int search(int arr[], int N, int X)
    {

        for(int i=0;i<N;i++){
            if(arr[i] == X)return i;
        }
        
        return -1;  
    }

};

//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends