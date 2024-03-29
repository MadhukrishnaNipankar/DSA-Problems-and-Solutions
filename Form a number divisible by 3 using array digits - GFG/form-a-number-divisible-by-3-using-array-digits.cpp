//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int sumOfAllDigits = 0;
        for(int i=0;i<N;i++){
            int currentNumber = arr[i];
            while(currentNumber){
                int lastDigit = currentNumber%10;
                sumOfAllDigits+=lastDigit;
                currentNumber/=10;
            }
        }
        
        if(sumOfAllDigits%3 == 0)return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends