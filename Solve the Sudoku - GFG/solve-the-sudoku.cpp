//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    
    bool isPlacementPossible(int row,int col,int element,int grid[][N]){
        
        // 3. check the current 3X3 matrix
        
                    // setting row position
                    int rowStart,colStart;
                    
            
                    if(row>=0 && row<=2){
                        rowStart=0;
                    }else if(row>=3 && row<=5){
                        rowStart=3;
                    }
                    else{
                        rowStart=6;
                    }
                    //setting column position
                    if(col>=0 && col<=2){
                        colStart=0;
                    }else if(col>=3 && col<=5){
                        colStart=3;
                    }
                    else{
                        colStart=6;
                    }
                    
                    for(int i=rowStart;i<rowStart+3;i++){
                        for(int j=colStart;j<colStart+3;j++){
                            if(grid[i][j] == element)return false;
                        }
                    }
        
        // 2. check the whole row
        for(int j=0;j<N;j++){
            if(grid[row][j] == element)return false;
        }
        
        // 3. check the whole column
        for(int i=0;i<N;i++){
            if(grid[i][col] == element)return false;
        }
        
        
        return true;

        
    }
    
    bool help(int row,int col,int grid[N][N]){
        
        // If we have reached the last row, the puzzle is solved.
        if(row == N && col == N)return true;
        
        if (row == N)
            return true;
            
        if(col == N)
        {
           return help(row+1,0,grid);
        }
            
        if(grid[row][col] != 0){
           return help(row,col+1,grid);
        }else{
            // row = 0,col = 1
            for(int i=1;i<=9;i++)
            {
                if(isPlacementPossible(row,col,i,grid)){
                    grid[row][col] = i; //element placed
                    
                   if(help(row,col+1,grid)){
                       return true;
                   }
                   
                    grid[row][col] = 0; // Backtrack if the placement does not lead to a solution.
                }
            }
            return false;
        }    
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        int row = 0,col = 0;
        return help(row,col,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
          for(int i=0;i<N;i++){
              for(int j=0;j<N;j++){
                  cout<<grid[i][j]<<" ";
              }
          }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends