//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string &s,vector<string>&ans,string &temp,unordered_map<int,bool> &used){
        if(temp.size() >= s.size()){
            ans.push_back(temp);
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
    vector<string> permutation(string s)
    {
     
       vector<string>ans;
       string temp = "";
       unordered_map<int,bool>used;
       solve(s,ans,temp,used);
         sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends