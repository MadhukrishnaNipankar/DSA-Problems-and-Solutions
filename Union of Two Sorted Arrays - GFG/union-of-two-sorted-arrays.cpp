//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
    //   vector<int>unionSet;
    //   map<int,int>hash;
       
    //   for(int i=0;i<n;i++){
    //       hash[arr1[i]]++;
    //   }
       
    //   for(int i=0;i<m;i++){
    //       hash[arr2[i]]++;
    //   }
       
    //     map<int,int>::iterator it = hash.begin();
       
    //   while (it != hash.end())
    //     {
    //         if(it->second > 1){
    //             unionSet.push_back(it->first);
    //         }
    //         ++it;
    //     }
        
    //     return unionSet;
    
      map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends