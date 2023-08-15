//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int element,vector<int>adjLs[],int visited[]){
        visited[element] = 1;
        for(auto it:adjLs[element]){
            if(!visited[it]){
                dfs(it,adjLs,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int>adjLs[V];
        // creating adjacency list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int visited[V] = {0};
        
        int provinces = 0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,adjLs,visited);
            }
        }
        
        return provinces;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends