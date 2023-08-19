//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
//   private:
//     bool dfs(int node, vector<int> adj[],int vis[],int pathVis[]){
//         vis[node] = 1;
//         pathVis[node] = 1;
        
//         // traverse for adjacent Nodes
//         for(auto it:adj[node]){
//             // when node is not visited
//             if(!vis[it]){
//                 if(dfs(it,adj,vis,pathVis))return true;
//             }
//             // if the node is visited
//             else if(pathVis[it]){
//                 return true;
//             }
//         }
        
//         pathVis[node] = 0;
//         return false;
//     }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//       int vis[V] = {0};
//       int pathVis[V] = {0};
       
//       for(int i=0;i<V;i++){
//           if(!vis[i]){
//               if(dfs(i,adj,vis,pathVis))return true;
//           }
//       }
       
//       return false;
//     }
    
    
	public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       int indegree[V] = {0};
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]){
	           indegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(indegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   vector<int>topo;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       topo.push_back(node);
	       
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(indegree[it] == 0)q.push(it);
	       }
	   }
	   
	   return topo.size() == V?false:true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends