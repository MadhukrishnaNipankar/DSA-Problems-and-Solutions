//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool PlacementPossible(int row,int col,int n,vector<vector<int>>&chessBoard){
        // check in leftward upper direction
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(chessBoard[i][j] == 1)return false;
        }
        
        // // check in left direction
        for(int j=col;j>=0;j--){
            if(chessBoard[row][j] == 1)return false;
        }
        
        
        // // // check in leftward down direction
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(chessBoard[i][j] == 1)return false;
        }
        
        
        return true;
    }
    void help(int col,vector<vector<int>>&chessBoard,vector<int>&temp,vector<vector<int>>&ans,int n){
        
        if(col >= n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(PlacementPossible(row,col,n,chessBoard)){
                temp.push_back(row+1);
                chessBoard[row][col] = 1;
                help(col+1,chessBoard,temp,ans,n);
                temp.pop_back();
                chessBoard[row][col] = 0;
            }
        }
        
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>chessBoard;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            chessBoard.push_back(temp);
        }
        
        int col = 0;
        vector<int>temp;   
        vector<vector<int>>ans;
        
        help(col,chessBoard,temp,ans,n);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends