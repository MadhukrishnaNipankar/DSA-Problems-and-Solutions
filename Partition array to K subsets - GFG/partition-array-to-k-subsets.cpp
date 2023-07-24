//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool help(int i,int bucketNum,int bucketSum,int requiredSum,int k,int input[],vector<int>&alreadyPicked,int size){
       if(bucketNum == k+1){
           return true;
       }
       
       if(bucketSum == requiredSum){
            return help(0,bucketNum+1,0,requiredSum,k,input,alreadyPicked,size);
       }
      if(bucketSum>requiredSum){
          return false;
      }
      if(i>=size){
          return false;
      }
        
        if(alreadyPicked[i] == 1){
            return help(i+1,bucketNum,bucketSum,requiredSum,k,input,alreadyPicked,size);
        }else{
            // pick
            bucketSum+=input[i];
            alreadyPicked[i] = 1;
            bool op1 = help(i+1,bucketNum,bucketSum,requiredSum,k,input,alreadyPicked,size);
            
            
            // not pick
            bucketSum-=input[i];
            alreadyPicked[i] = 0;
            bool op2 =  help(i+1,bucketNum,bucketSum,requiredSum,k,input,alreadyPicked,size);         
            
            
            return op1 | op2;
             
        }
        
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        vector<int>alreadyPicked(n,0);
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        
        if(sum%k != 0){
            return false;
        }
        
        int requiredSum = sum/k;
        
        return help(0,1,0,requiredSum,k,a,alreadyPicked,n); 
         
        
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends