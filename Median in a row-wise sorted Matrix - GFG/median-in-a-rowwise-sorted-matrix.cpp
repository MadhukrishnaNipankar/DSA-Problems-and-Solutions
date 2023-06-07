//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int countOfLessElements(vector<vector<int>> &matrix,int R,int C,int target){
        int totalCount = 0;
        for(int i=0;i<R;i++){
            int low = 0;
            int high = C-1;
            int count = 0; 
            int mid = 0;
            while(low<=high){
                 mid = low + (high-low)/2;
                
                if(matrix[i][mid] <= target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            
            //now we got rightmost element which is less than or equal to the target 
            totalCount+=low;
            
        }
        return totalCount;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int totalElements = R*C;
        
        
        
        int low = 1;
        int high = 2000;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(countOfLessElements(matrix,R,C,mid) <= totalElements/2){
                  low = mid + 1;
            }
            else{
                high = mid - 1;
            }
          
        }
        
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends