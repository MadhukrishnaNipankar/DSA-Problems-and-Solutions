//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

   long long int i = 1, fact = 1;
   
   long long int calculateFactorial(long long int N){
        if(i>N){
            return fact;
        }
        fact = fact*i;
        i++;
        calculateFactorial(N);
    }

   
    vector<long long> factorialNumbers(long long N)
    {
        vector<long long>v;
        long long factorial;
        long long int i = 1;
        while(true){
           factorial = calculateFactorial(i); 
           if(factorial > N){
               break;
           }
           v.push_back(factorial);
           i++;
        }
        
     return v;
    }
    

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends