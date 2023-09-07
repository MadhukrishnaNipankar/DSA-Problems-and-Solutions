//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int help(int n){
            if(n <= 0)return 0;
            
            int byTwo = (n/2);
            int byThree = (n/3);
            int byFour = (n/4);
           
            
            int ans1 = max(byTwo,help(byTwo));
            int ans2 = max(byThree,help(byThree));
            int ans3 = max(byFour,help(byFour));
            
            return ans1+ans2+ans3;            
        }
        int maxSum(int n)
        {
            return help(n);
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends