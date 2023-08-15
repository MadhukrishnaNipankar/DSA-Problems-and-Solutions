//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&grid){
       visited[row][col] = 1;
       queue<pair<int,int>>q;
       q.push({row,col});
       
       
       int n = grid.size();
       int m = grid[0].size();
       
       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           
        //   traverse in the neighbours and mark them if it is a land 
           for(int i=-1;i<=1;i++){
               for(int j=-1;j<=1;j++){
                   int newRowIndex = row+i;
                   int newColIndex = col+j;
                   
                   if(newRowIndex>=0 && newRowIndex<n && newColIndex>=0 && newColIndex<m){
                      //the element has to be a land   
                       if(grid[newRowIndex][newColIndex] == '1'){
                           //the newRow and newCol has to be non visited as well   
                           if(!visited[newRowIndex][newColIndex]){
                               visited[newRowIndex][newColIndex] = 1;
                               q.push({newRowIndex,newColIndex});
                           }
                       }
                   }
               }
           }
       }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                   count++;
                   bfs(i,j,visited,grid);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends