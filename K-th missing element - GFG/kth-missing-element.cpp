//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
   int missingNumber = 0;
   int kthMissing = 0;
 
   int i = a[0];
   
   // 32 59 77
    /*
    i = 32
    i = 33
    
    
    */
    int indice = 0;
      while(indice<n){
            
            if(a[indice] == i){
                indice++;
            }
            else{
                missingNumber = i;
                kthMissing++;
            }
            

            
             if(kthMissing == k)return missingNumber;
         
            
            i++;
       }
      return -1;
    
}