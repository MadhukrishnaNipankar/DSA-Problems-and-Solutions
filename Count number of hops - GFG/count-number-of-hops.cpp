//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long help(int i, int n,vector<int>&mem) {
    if (i > n) return 0; // If you go beyond the top step, there are no ways.
    if (i == n) return 1; // If you reach the top step, there's one way.
    if(mem[i]!=-1)return mem[i];
    long long ans = (help(i + 1, n,mem) + help(i + 2, n,mem) + help(i + 3, n,mem)) % 1000000007;
    mem[i] = ans;
    return mem[i];
}

// Function to count the number of ways in which frog can reach the top.
long long countWays(int n) {
    vector<int>mem(n+1,-1);
    if (n <= 1) return 1;
    return help(0, n,mem);
}
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends