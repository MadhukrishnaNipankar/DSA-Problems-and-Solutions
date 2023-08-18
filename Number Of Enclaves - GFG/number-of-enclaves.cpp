//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int delRow[],int delCol[]){
        vis[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // trying to visit all the four directions
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                if(!vis[nRow][nCol]){
                    if(grid[nRow][nCol] == 1){
                        dfs(nRow,nCol,grid,vis,delRow,delCol);
                    }
                }
            }
        }
        
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // 1. visit all the boundary 1's and all connected to it!
        // 2. count the 1's in the visited matrix which are not visited. Done
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        
        // creating a visited matrix
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        // visiting boundaries
        
            // top and bottom boundaries
            for(int j=0;j<m;j++){
                // for top row
                if(!vis[0][j] && grid[0][j] == 1){
                    dfs(0,j,grid,vis,delRow,delCol);
                }
                
                // for bottom row
                 if(!vis[n-1][j] && grid[n-1][j] == 1){
                    dfs(n-1,j,grid,vis,delRow,delCol);
                }
            }     
            
            
            // for left and right boundaries
            for(int i=0;i<n;i++){
                // for left col
                if(!vis[i][0] && grid[i][0] == 1){
                    dfs(i,0,grid,vis,delRow,delCol);
                }
                
                if(!vis[i][m-1] && grid[i][m-1]){
                    dfs(i,m-1,grid,vis,delRow,delCol);
                }
            }
            
            
            int count = 0;
            // traverse 
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        count++;
                    }
                }
            }
            
            return count;
        
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends