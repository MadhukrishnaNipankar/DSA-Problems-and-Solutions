//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
      
      int n  = grid.size();
      int m = grid[0].size();
      
      int visited[n][m];   
      queue<pair<pair<int,int>,int>>q; //{{row,col},time}
     
      //finding the initially rotten oranges
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j] == 2){
                  q.push({{i,j},0});
                  visited[i][j] = 2;
              }else{
                  visited[i][j] = 0;
              }
          }
      }
    
    
      int tm = 0;
      int deltaRow[] = {-1,0,1,0};
      int deltaCol[] = {0,1,0,-1};
      //performing bfs
      while(!q.empty()){
          int r = q.front().first.first; //r: row,c: col,t:time
          int c = q.front().first.second;
          int t = q.front().second;
          tm = max(tm,t);
          q.pop();
          
         
          
          for(int i=0;i<4;i++){
              int nRow = r + deltaRow[i];
              int nCol = c + deltaCol[i];
              
             //certain checks
             if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                 // if not rotten already
                 if(visited[nRow][nCol] == 0){
                    //  if it is fresh
                    if(grid[nRow][nCol] == 1){
                        q.push({{nRow,nCol},t+1});
                        visited[nRow][nCol] = 2;
                    }
                 }
             }
          }
          
          
      }
      
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(visited[i][j]!=2 && grid[i][j] == 1){
                  return -1;
              }
          }
      }
      
      return tm;  
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends