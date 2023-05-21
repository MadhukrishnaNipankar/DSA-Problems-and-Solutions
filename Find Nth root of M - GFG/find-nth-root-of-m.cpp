//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n,  int m)
	{
	    int count = 1;
	        int target = m;
	        int low = 1,high = m;
	        int mid;
	        while(low<=high){
	             mid = (low+high)/2;
	          
	             
	             
	            if(pow(mid, n) == target)
	                 return mid;
                else if(pow(mid, n) < target)
                     low = mid+1;
                else
                    high = mid-1;
	        }
	        return -1;
	}  
	
	    /*
	    thinking:)
	    
	    case 1:
	    n = 2, m = 9, find 9 root of 2
	    
	    0    4     9
	    0+9 / 2   = 4
	    4^2 = 16>9
	    
	    0    2     4
	    0+4/ 2   = 2
	    2^2 = 4<9
	    
	    
	    
	    2     3      4
	    2+4 / 2 = 3
	    3^2 = (9 == target)
	    return 3
	    
	    
	   
	    low = 0;
	    high = m;
	    mid = (low+high)/2
	    
	    if(a[mid] > target)
	    high = mid
	    
	    else if(a[mid]<target)
	    low = mid
	    
	    else
	    return mid;
	    
	    
	    
	    
	    
	    case 2:
	    n = 3,  m = 9, find 9 root of 3
	    0     4      9
	    4^3 = 64 > target
	    
	    0      2      4
	    2^3 = 8 < target
	    
	    
	    2       3       4 
	    3^3 = 27 >target
	    
	    
	    2       2        3
	    
	    
	    
	    
	    
	    case 3:
	   // n = 4, m = 16, find 16 root of 4 
	  
	    0      8        16
	    mid = 0+16/2 = 8
	    8^4 = 4096 > target
	    
	    0        4        8
	    4^4 = 256 > target
	    
	    
	    0        2         4
	    2^4 = 16 = target
	    
	    
	    
	    n = 6
	    0         2048          4096
	    2048^6
	    
	    
	    
	    
	    
	    
	    
	    
	    */
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends