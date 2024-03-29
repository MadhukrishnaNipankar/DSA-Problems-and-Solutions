//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        int row=matrix.size();
        int col=matrix[0].size();

        // swapping arr[i][j]  with [j][i]
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        // reverse the columns of the matrix
        int i = 0,j=row-1;
        while(i<j){
            for(int k=0;k<col;k++){
                swap(matrix[i][k],matrix[j][k]);
            }
            i++;
            j--;
        }
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends