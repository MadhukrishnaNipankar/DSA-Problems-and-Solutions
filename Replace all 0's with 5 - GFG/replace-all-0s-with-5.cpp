//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    int newNumber = 0;
    int position = 1;
    while(n){
        int lastDigit = n%10;
        if(lastDigit == 0){
            newNumber+=position*5;
        }else{
            newNumber+=position*lastDigit;
        }
        position*=10;
        n/=10;
    }
    
    return newNumber;
}