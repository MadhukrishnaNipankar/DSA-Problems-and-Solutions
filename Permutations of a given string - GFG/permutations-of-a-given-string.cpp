//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
void findPermutations(string& str, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(str);
        return;
    }

    for (int i = l; i <= r; i++) {
        bool isDuplicate = false;
        for (int j = l; j < i; j++) {
            if (str[j] == str[i]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            swap(str[l], str[i]);
            findPermutations(str, l + 1, r, result);
            swap(str[l], str[i]); // Backtrack
        }
    }
}

vector<string> find_permutation(string S) {
    vector<string> result;
    sort(S.begin(), S.end());
    findPermutations(S, 0, S.length() - 1, result);
    return result;
}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends