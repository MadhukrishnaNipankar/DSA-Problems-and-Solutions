//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour. 
   bool isSafe(int v, bool graph[101][101], vector<int>& color, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, vector<int>& color, int v, int n) {
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, n)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0);

    if (graphColoringUtil(graph, m, color, 0, n)) {
        return true;
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends