//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    
		    int arrSize = v.size();
		   
		   
		    //  if array size is odd
		    if(arrSize%2 != 0){
		        	int mid = arrSize/2;
		            return v[mid];
            }

            // if array size is even
		
		  int mid1 = arrSize/2;
		  int mid2 = mid1-1;
		  return int((v[mid1]+v[mid2])/2);
		    
		    
		    
		  
		  
		    
		    
		    
		  
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends