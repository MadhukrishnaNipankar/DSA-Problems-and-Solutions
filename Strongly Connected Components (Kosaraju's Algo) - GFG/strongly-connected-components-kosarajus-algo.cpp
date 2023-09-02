//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& finishOrder) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, finishOrder);
            }
        }
        finishOrder.push_back(node);
    }

    void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs2(it, adj, vis);
            }
        }
    }

public:
    // Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> finishOrder;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, finishOrder);
            }
        }

        // Creating the transpose graph (adjT)
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (int it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Last DFS using the finish order
        int scc = 0;
        for (int i = V - 1; i >= 0; i--) {
            int node = finishOrder[i];
            if (!vis[node]) {
                scc++;
                dfs2(node, adjT, vis);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends