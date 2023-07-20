//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool checkPalindrome(int i,string &S){
        if(i>=S.size()/2)return true;
        if(S[i]!=S[S.size()-i-1])return false;
        return checkPalindrome(i+1,S);
	}
	
	int isPalindrome(string S)
	{
	    if(checkPalindrome(0,S))return 1;
	    else return 0;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends