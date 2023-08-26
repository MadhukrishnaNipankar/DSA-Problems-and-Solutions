//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // diff,(row,col)
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        // visited array
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        // starting cell
        pq.push({0,{0,0}});

        // ṃarking visited
        dist[0][0] = 0;
        
        int delRow[] ={-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        // BFS
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                // if in boundaries
                if(nRow>=0 && nRow<n && nCol >=0 && nCol<m){
                    int newEffort = max(diff,abs(heights[nRow][nCol] - heights[row][col]));
                    
                    if(dist[nRow][nCol] > newEffort){
                        dist[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                    
                    
                    
                }
            }
            
        }
    
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends