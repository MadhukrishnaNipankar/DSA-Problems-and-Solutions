//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
            string reversed = "";
            int lastStop = S.length();
            for(int i=S.length()-1;i>0;i--){
                if(S[i] == '.'){
                  
                    for(int j=i+1;j<lastStop;j++){
                        reversed+=S[j];
                    }
                    reversed+='.';
                    lastStop = i;
                }
            }
            
            int i = 0;
            while(S[i]!='.' && i<=S.length()-1){
                reversed+=S[i];
                i++;
            }
            
            
            return reversed;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends