//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S == 0 && N>1)return "-1";
        
        
        int maxrange = N*9;
        if ( S>maxrange) return "-1";
        int diff = maxrange-S;
        // Making the Number
        string output = "";
        
        if(diff<=9){
            for(int i=0;i<N-1;i++){
            output+="9";
            }
            output+=to_string(9-diff);
            return output;
        } 
        
        
        // for diff greater than 9
        int N2 = N;
        int lastDigit = 0;
        while(true){
            if(N2*9 > S){ // n = 4,s = 2
                          // n = 3, s = 2
                          // n = 2, s = 2
                          // n = 1,s = 2
                int diff = (N2*9)-S; // 36 - 2 = 34
                                     // 27 - 2 = 25
                                     // 18 - 2 = 16
                                     // 9 - 2 = 7
                if(diff>9){
                    N2--; 
                }
                else{
                    lastDigit = 9-diff; // lastDigit = 2
                    break;
                }
            }
        }
        
        output = "";
        for(int i=0;i<N;i++){
            if(i < N2-1){
                output+="9";
            }
            else if(i == N2-1){
                output+=to_string(lastDigit);
            }
            else{
                output+="0";
            }
            
        }
        
        return output;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends