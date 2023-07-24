//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findPaths(int row,int col,string &temp,vector<string>&ans,vector<vector<int>> &maze,int &n){
        // if mouse goes outof boundary
        if(row<0 || row == n || col<0 || col == n){
            return;
        }
         
          // if mouse reaches the destination
        if(row == n-1 && col == n-1){
            ans.push_back(temp);
            return;
        }
       
        if(maze[row][col] == 0)return;
        
      
            
        // Mark the current cell as visited by setting it to 0.
         maze[row][col] = 0;
       
        
        // check downward direction
        temp.push_back('D');
        findPaths(row+1,col,temp,ans,maze,n);
        // after finding all the paths from downward direction
        temp.pop_back();
        
        
         // check left direction
       temp.push_back('L');
        findPaths(row,col-1,temp,ans,maze,n);
        // after finding all the paths from left direction
        temp.pop_back();
        
        
         // check right direction
         temp.push_back('R');
        findPaths(row,col+1,temp,ans,maze,n);
        // after finding all the paths from right direction
        temp.pop_back();
        
        
          // check up direction
         temp.push_back('U');
        findPaths(row-1,col,temp,ans,maze,n);
        // after finding all the paths from up direction
        temp.pop_back();
        
        // Mark the current cell as unvisited by setting it back to 1.
        maze[row][col] = 1;
        
        // done :)
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string temp = "";
        int row = 0,col = 0;
         // Check if the destination cell is blocked
        if (m[n - 1][n - 1] == 0) {
            return ans;
        }
            
        findPaths(row,col,temp,ans,m,n);
        
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends