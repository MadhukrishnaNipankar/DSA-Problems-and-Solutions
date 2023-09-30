//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<int>rowTemp(r,0);
        vector<int>colTemp(c,0);
        
        // traverse the matrix and mark temp vectors
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == 1){
                    rowTemp[i] = 1;
                    colTemp[j] = 1;
                }
            }
        }
        
        
        // mark the elements as 1 based on the temp vectors
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rowTemp[i] || colTemp[j])matrix[i][j] = 1;
            }
        }
        
        // Done :)
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends