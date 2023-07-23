//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void helper(int i,int input[],string &temp,vector<string>&ans,unordered_map<int,string>&hash,int N){
        
        if(i == N){
            ans.push_back(temp);
            return;
        }
        
        string str = hash[input[i]]; //str = a b c
       
        for(int j=0;j<str.size();j++){
            temp+=str[j];
            helper(i+1,input,temp,ans,hash,N);
            temp.pop_back();
           
        }
        
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
       unordered_map<int,string>hash;
       hash[2]="abc";
       hash[3]="def";
       hash[4]="ghi";
       hash[5]="jkl";
       hash[6]="mno";
       hash[7]="pqrs";
       hash[8]="tuv";
       hash[9]="wxyz";
       
       vector<string>ans;
       string temp = "";
       helper(0,a,temp,ans,hash,N);
       
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends