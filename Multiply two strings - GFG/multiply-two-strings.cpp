//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
   string multiplyStrings(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    
    // Handle the sign of the result
    int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1 = s1.substr(1);
        n1--;
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2 = s2.substr(1);
        n2--;
    }
    
    // Reverse the strings for easier multiplication
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    vector<int> result(n1 + n2, 0);
    
    // Perform multiplication
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i + j] += (s1[i] - '0') * (s2[j] - '0');
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    
    // Handle carry and construct the result string
    int idx = n1 + n2 - 1;
    while (idx > 0 && result[idx] == 0) {
        idx--;
    }
    string finalResult = "";
    while (idx >= 0) {
        finalResult += to_string(result[idx]);
        idx--;
    }
    
    if (finalResult.empty()) {
        return "0";
    }
    
    // Add the sign to the result
    if (sign == -1) {
        finalResult = "-" + finalResult;
    }
    
    return finalResult;
}

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends