//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>>q; //{row,col,distance}
	    
	    int delRow[] = {-1,0,1,0};
	    int delCol[] = {0,1,0,-1};
	    
	    // initial Configuration
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }else{
	                vis[i][j] = 0;
	            }
	        }
	    }
    
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[row][col] = steps;
            
            // travelling for 4 directions
            for(int i=0;i<4;i++){
                int nRow = row+delRow[i];
                int nCol = col+delCol[i];
                
                // if inside the boundaries of matrix and that cell is not already visited
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] == 0){
                        vis[nRow][nCol] = 1;
                        q.push({{nRow,nCol},steps+1});
                }
            }     
        }

        return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends