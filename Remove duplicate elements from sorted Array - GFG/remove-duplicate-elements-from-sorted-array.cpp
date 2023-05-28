//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        /*
        1 1 1 1 2 2 2 4 5 7 9
            
        1 2      
        
        1 2  
        count = 1
        
        
        
        
        1 2 4 5 7 9 1 2 2
        
        
        
        */
        
        int count = 1;
        
        int i=1;
        int currentIndice = 1;
        
        while(i<n){
            if(a[i] == a[i-1]){
                i++;
            }
            else{
                a[currentIndice++] = a[i];
                count++;
                i++;
            }
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends