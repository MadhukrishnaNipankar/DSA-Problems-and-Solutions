//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		  int originalNumber = n;
		  int revNumber =  0;
		  while(n){
		      int lastDigit = n%10;
		      //forming a rev number
		      revNumber = (revNumber * 10)+lastDigit;
		      
		      n/=10;
		      
		  }
		  
		  if(originalNumber == revNumber){
		      return "Yes";
		  }
		  return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends