//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int countOfLesserElements(vector<int> &array1,vector<int>&array2,int target){
        int totalCount = 0;
        if(array1.size() > 0){
                int low = 0;
                int high = array1.size()-1;
                
                while(low<=high){
                    int mid = low + (high-low)/2;
                    if(array1[mid] <= target){
                        low = mid + 1;
                    }    
                    else{
                        high = mid - 1;
                    }
                }
                
                        
            totalCount+=low;
        }
    

        if(array2.size() > 0){
            int low = 0;
            int high = array2.size()-1;
        
            while(low<=high){
                int mid = low + (high-low)/2;
                if(array2[mid] <= target){
                    low = mid + 1;
                }    
                else{
                    high = mid - 1;
                }
            }
        
             totalCount+=low;
        }
        
        
        
      
        
    
        return totalCount;
        
    }
    
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int totalElements = array1.size() + array2.size();
        double low = 0;
        double high =0;
       
       
        if(array1.size() == 0 && array2.size() == 0){
            return -1;
        }else if(array1.size() == 0){
             low = array2[0];
             high = array2[array2.size()-1];
        }
        else if(array2.size() == 0){
             low = array1[0];
             high = array1[array1.size()-1];
        }
        else{
             low = min(array1[0],array2[0]);
             high = max(array1[array1.size()-1],array2[array2.size()-1]); 
        }

       
        double tempLow = low;
        double tempHigh = high;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(countOfLesserElements(array1,array2,mid) <= totalElements/2){
               low = mid + 1; 
            }
            else{
                high = mid-1;
            }
        }
        
        
        // cout<<low<<endl;
        
        if(totalElements%2 != 0)return low;
        
        double low1 = low;
         low = tempLow;
         high = tempHigh;
    
        while(low<=high){
            int mid = low + (high-low)/2;
            if(countOfLesserElements(array1,array2,mid) <= (totalElements/2)-1){
               low = mid + 1; 
            }
            else{
                high = mid-1;
            }
        }

     
    
        
        return (low1+low)/2;
        
    }
    

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends