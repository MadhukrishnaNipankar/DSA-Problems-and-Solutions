//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



vector<int> find(int arr[], int n , int target )
{
    
    int low = 0,high = n-1;
    int leftMostOccurence = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            leftMostOccurence = mid;
            high = mid-1;
        }
        else if(arr[mid] > target){
           high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    

    low = 0,high = n-1;
    int RightMostOccurence = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            RightMostOccurence = mid;
            low = mid+1;
        }
        else if(arr[mid] < target){
            low = mid+1;  
        }
        else{
            high = mid-1;
        }
    }
    


    vector<int>result;

    result.push_back(leftMostOccurence);
      result.push_back(RightMostOccurence);
    return result;
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends