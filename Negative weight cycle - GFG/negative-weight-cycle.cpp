//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
    const int INF = 1e9;
    
    // Step 1: Initialize the distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    // Step 2: Update the distance matrix based on the edges
    for (const auto& edge : edges) {
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];
        dist[src][dest] = weight;
    }
    
    // Step 3: Perform the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Step 4: Check for negative weight cycles
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            return 1;
        }
    }
    
    return 0;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends