//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string longest(string names[], int n)
    {
        int longestIndex = 0;
        int longestLength = names[0].length();
        
        for(int i=0;i<n;i++){
            if(longestLength < names[i].length()){
                longestLength = names[i].length();
                longestIndex = i;
            }
        }
        
        return names[longestIndex];
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string names[n];
		
		for(int i=0;i<n;i++)
			cin>>names[i];
		Solution ob;
		cout<< ob.longest(names, n) << endl;
	}
}

// } Driver Code Ends