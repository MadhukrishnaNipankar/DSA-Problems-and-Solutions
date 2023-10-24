//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
/*
    Before doing this, we should know 
    1. n1 xor 0 = n1
    2. n1 xor n1 = 0
    3. ordering in xor operations doesn't matter
    
    Here is the logic:
    
    1. a = a xor b 
    now a has a as well as b.
    
    2. b = a xor b
    we know that a already has (a and b). so it a xor b will be like (
        a xor b xor b
    )
    Here b xor b will cancel each other.
    hence b will only have a.
    
    3. a = a xor b
    the above line is equivalent to this:-
    a = (a xor b xor a)
    Here a will cancel each other
    Hence a will only have b.

*/
    pair<int, int> get(int a, int b){
        pair<int,int>ans;
        a = a^b;
        b = a^b;
        a = a^b;
        
        ans.first = a;
        ans.second = b;
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
        int a, b;
        cin >> a >> b;
        
        Solution ob;
        pair<int, int>p = ob.get(a, b);
        cout << p.first << ' ' << p.second << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends