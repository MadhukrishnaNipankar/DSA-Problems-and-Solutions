//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
    unordered_map<char, int> countMap;

    // Count the occurrences of each character in the string
    for (char c : S)
        countMap[c]++;

    // Find the first non-repeating character
    for (char c : S)
    {
        if (countMap[c] == 1)
            return c;
    }

    return '$'; // Return '$' if there's no non-repeating character
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends