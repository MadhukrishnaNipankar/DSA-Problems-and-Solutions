//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>hash;
    
    for(int i=0;i<n;i++){
        hash[a1[i]]++;
    }
    
    /*
    11 1
    7 1 
    1 1
    13 1
    21 1
    3 2/
    7 1
    */
    
//   for(auto it:hash){
//       cout<<it.first<<" : "<<it.second<<endl;
//   }    
    
   for(int i=0;i<m;i++){
       if(hash[a2[i]] <=0)return "No";
      
       if(hash[a2[i]]-1 == 0){
           hash[a2[i]]=-1;
       }
       else{
           hash[a2[i]]--;
       }
   }
    
    return "Yes";
    
}