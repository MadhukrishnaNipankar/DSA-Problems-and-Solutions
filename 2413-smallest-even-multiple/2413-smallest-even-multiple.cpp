class Solution {
public:
    int smallestEvenMultiple(int n) {
        int multipleOfN = n,i = 1;
        while((2*i)!= multipleOfN){
            if(multipleOfN < (2*i)){
                multipleOfN += multipleOfN;
                continue;
            }
            
            i++;
        }
        
        return multipleOfN;
    }
};

/*
Approach: 
1] Store n in a variable 'multipleOfN'
2] initialize i = 1. This 'i' will be used for iteration, i.e checking the 2's table
3] loop until value of 2*i is not equal to multipleOfN
4] Inside loop -> check if the value of multipleOfN is less than 2*i.
5] If yes, multipleOfN = multipleOfN + multipleOfN. and continue to next iteration
6] If no, then i++

If multipleOfN becomes equal to 2*i then the loop gets exited .
And the value is returned,which is the smallest multiple of 2 and n.
*/