//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int>result;
        int maximumNumber = a[n-1];
        
        //  // O(n)
        for(int i = n-1;i>=0;i--){
            maximumNumber = max(maximumNumber,a[i]);
            if(maximumNumber == a[i])result.push_back(a[i]);
        }
        
        // O(n)
        reverse(result.begin(), result.end());
 
        return result;
    }
    
    /*
    Thinking :)
    
    16,17,4,3,5,2
    i
    max = a[n-1] = 2
    ans = 2 (by default)
    i--;
    
    
    max = max(5,2) = 5
    if(max == a[i])
    put it into answer
    ans = 2 5
    i--
    
    
    max = max(3,5) = 5
    here, max is not equal to answer
    ans = 2 5
    i--
    
    max = max(3,5) = 5
    here, max is not equal to answer
    ans = 2 5
    i--
    
    
    
    
    
    
    
    
    
    
    */
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends