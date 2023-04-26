//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int binarySearch(vector<int>arr,int low,int high,int target){
        int mid = low + (high-low)/2;
        while(low<=high){
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid]>target){
                high = mid - 1;
            }
            else{
                low = low + 1;
            }
            mid = low + (high-low)/2;
        }
        
        return low;
        

     
    }
    
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int searchedIndex = binarySearch(Arr,0,N-1,k);
        if(searchedIndex !=-1)return searchedIndex;
        return searchedIndex;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends