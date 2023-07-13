//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        
        // Step 1 : Inserting all elements into unordered set
        unordered_set<int>hashSet;
        
        for(int i=0;i<N;i++){
            hashSet.insert(arr[i]);
        }
        
        
        int longestSequence = 1;
        
        // iterating into the set
        for(auto it:hashSet){
            // check if current element is the first of its sequence
            int count = 1;
            if(hashSet.find(it-1) == hashSet.end()){
                int x = it;
                while(hashSet.find(x+1) != hashSet.end()){
                    x++;
                    count++;
                }
            }
            
            longestSequence = max(longestSequence,count);
            
        }
        
        
        return longestSequence;
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends