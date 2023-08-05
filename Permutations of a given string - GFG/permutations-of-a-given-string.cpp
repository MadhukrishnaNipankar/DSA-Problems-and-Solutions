//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	  void solve(string &s,set<string>&ans,string &temp,unordered_map<int,bool> &used){
           if(temp.size() >= s.size()){
            ans.insert(temp);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            // AB
            
            // if this index is already taken then don't take it again
            if(!used[i]){
                temp+=s[i]; //AB
                used[i] = true;
                solve(s,ans,temp,used);
                
                temp.pop_back();
                used[i] = false;
            }
        }  
        
    }
		vector<string>find_permutation(string s)
		{
        	  vector<string>res;
               set<string>ans;
               string temp = "";
               unordered_map<int,bool>used;
               solve(s,ans,temp,used);
               
               for(auto it:ans){
                   res.push_back(it);
               }
               
               return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends