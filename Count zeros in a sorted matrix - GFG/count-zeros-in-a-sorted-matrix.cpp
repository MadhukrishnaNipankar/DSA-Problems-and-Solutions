//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
	int countZeros(vector<vector<int>>A)
	{
	    int length = A.size();
	    int totalZeroes = 0;
	    
		for(int i=0;i<length;i++){
		    int innerLength = A[i].size()-1;
		  
		    for(int j=innerLength;j>=0;j--){
		        if(A[i][j] == 0){
		           totalZeroes+=j+1; 
		           break;
		        }
		      
		    }
		}
		
		return totalZeroes;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends