//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
         vector<pair<int,int>>result;
         pair<int,int>temp;
          sort(A, A + N);
          sort(B, B + M);
          
          int i=0,j=M-1;
          
          while(i<N && j>=0)
          {
              if(A[i]+B[j] == X){
                  temp.first = A[i];
                  temp.second = B[j];
                  result.push_back(temp);
                  i++;
              }
              else if(A[i]+B[j]<X){
                  i++;
              }
              else{
                  j--;
              }
          }
          
          
          return result;
          
          /*
          1 2 4 5 7
          i i i i i
          3 4 5 6 8
          j j j j j      
          
          1+8 = 9 print
          i++
          if(A[i]+B[j] > X)j--;
          else if(A[i]+B[j] < X)i++;
          if(equal then print)i++;

          */
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends