//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        bool negative = false;
        int ans = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            if(i==0 && str[0] == '-'){
                negative = true;
            }else if(!isdigit(str[i])){
                return -1;
            }else{
                ans =ans*10+(str[i]-'0');
            }
        }
        
        if(negative)ans*=-1;
        
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends