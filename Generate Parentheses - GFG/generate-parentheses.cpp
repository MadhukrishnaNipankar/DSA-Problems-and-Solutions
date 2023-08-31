//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
  private:
void help(vector<string>& ans, int n, int oCount, int cCount, string temp) {
    if (temp.size() == 2 * n) {  // Check if the length is equal to 2*n
        ans.push_back(temp);
        return;
    }
    
    // add opening
    if (oCount < n) {
        temp += "(";
        oCount++;
        help(ans, n, oCount, cCount, temp);
        temp.pop_back();
        oCount--;
    }
    
    // add closing
    if (cCount < oCount) {
        temp += ")";
        cCount++;
        help(ans, n, oCount, cCount, temp);
        temp.pop_back();
        cCount--;
    }
}

public:
vector<string> AllParenthesis(int n) {
    vector<string> ans;
    string temp = "";
    int oCount = 0, cCount = 0;
    help(ans, n, oCount, cCount, temp);
    return ans;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends