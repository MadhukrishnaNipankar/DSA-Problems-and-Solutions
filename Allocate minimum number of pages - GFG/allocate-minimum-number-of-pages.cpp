//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isAllocationPossible(int A[], int N, int M,int mid){
      int studentCount = 1;
      int pageSum = 0;
      
      for(int i=0;i<N;i++){
          if(pageSum + A[i] <=mid){
              pageSum+=A[i];
          }
          else{
              studentCount++;
              if(studentCount > M || A[i]>mid)return false;
              pageSum = A[i];
          }
      }
      return true;
    }

    int findPages(int A[], int N, int M) 
    {
         if (M > N) {
             return -1; // Not enough books to allocate to each student
         }
         
         int totalPages = 0;
         int minimumPages = A[0];
        
        
        // finding minimum and totalPages
        for(int i=0;i<N;i++){
            totalPages+=A[i];
            minimumPages = min(minimumPages,A[i]);
        }
        
        // cout<<minimumPages<<" : "<<totalPages<<endl;
        int low = minimumPages;
        int high = totalPages;
        int answer = -1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
           
          if(isAllocationPossible(A,N,M,mid)){
              answer = mid;
              high = mid-1;
          }
          else{
              low = mid+1;
          }
        }
        
         return answer;
 
        
    }

    
    /*
    Intution:
    1]
    lowest number of pages that can be allocated
    eg. 
    12 12 12 12
    M=4
    
    here, each student will get 1 book of 12 pages
    hence the minimum answer would be 12.
    
    conclusion:
    we can consider minimum in the array as our 'low'
    
    2] The highest possible number of pages that can be allocated 
    e.g.
    10 20 30
    M = 1
    
    as there is only one student, all the books will be allocated to that student. 
    hence pages possible in this case would be : 10+20+30 = 60
    
    conclusion , we can consider totalNumberOfPages as our 'high'
    */
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends