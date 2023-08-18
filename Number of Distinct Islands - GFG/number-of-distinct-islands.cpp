//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,int baseRow,int baseCol,vector<vector<int>>& grid,vector<vector<int>>& vis, vector<pair<int,int>>&island,int n,int m){
        vis[row][col] = 1;
        island.push_back({row-baseRow,col-baseCol});
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            //if the cell is inside the boundaries 
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                // if not visited
                if(!vis[nRow][nCol]){
                    // if the element is 1
                    if(grid[nRow][nCol] == 1){
                        dfs(nRow,nCol,baseRow,baseCol,grid,vis,island,n,m);
                    }
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        // creating a visited matrix
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>>island;
                    int baseRow = i;
                    int baseCol = j;
                    dfs(i,j,baseRow,baseCol,grid,vis,island,n,m);
                    ans.insert(island);
                }            
            }
        }
        
        
        return ans.size();
        
        
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends