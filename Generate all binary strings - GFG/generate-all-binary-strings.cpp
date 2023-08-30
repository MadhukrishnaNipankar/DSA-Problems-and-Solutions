//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void doIt(vector<string>&ans,string &temp,int len,int num,char adj){
             if(len == num){
                 ans.push_back(temp);
                 return;
             }
             
           //if adj is 0 then can pick both elements
           if(adj == '0'){
            //  pick 0
                temp+='0';
                len++;
                adj = '0';
                doIt(ans,temp,len,num,adj);
                
                temp.pop_back();
                len--;
            // pick 1
                 temp+='1';
                 len++;
                 adj = '1';
                 doIt(ans,temp,len,num,adj); 
                 temp.pop_back();
                 len--;
           }else if(adj == '1'){
            //   pick 0
                temp+='0';
                len++;
                adj = '0';
                doIt(ans,temp,len,num,adj);
                temp.pop_back();
                len--;
          }
              
        
        return;  
                
    }
    void generateBinaryStrings(int num){
        vector<string>ans;
        string temp = "";
        char adj = '0';
        doIt(ans,temp,0,num,adj);
        
        for(auto it: ans){
            for(auto it2:it){
                cout<<it2;
            }
            cout<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends