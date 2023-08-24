//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
            if(source == destination)return 0;
       
            int n = grid.size();
            int m = grid[0].size();
            
            queue<pair<int,pair<int,int>>>q;
            vector<vector<int>>dist(n,vector<int>(m,1e9));
            
            dist[source.first][source.second] = 0;
            q.push({0,{source.first,source.second}});
            
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                
                int d = it.first;
                int r = it.second.first;
                int c = it.second.second;
                
                for(int i=0;i<4;i++){
                    int newR = r + delRow[i];
                    int newC = c + delCol[i];
                    
                    // if in boundaries
                    if(newR >=0 && newR<n && newC >=0 && newC<m){
                        if(grid[newR][newC] == 1){
                            if(d + 1 < dist[newR][newC]){
                                dist[newR][newC] = d + 1;
                                
                                if(newR == destination.first && newC == destination.second){
                                    return d+1;
                                }
                                
                                q.push({d+1,{newR,newC}});
                            }
                        }
                    }
                }
                
            }
          
          
          return -1;  
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends