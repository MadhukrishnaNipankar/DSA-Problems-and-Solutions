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
My Approach (Implemented in the above code): 
1] Store n in a variable 'multipleOfN'
2] initialize i = 1. This 'i' will be used for iteration, i.e checking the 2's table
3] loop until value of 2*i is not equal to multipleOfN
4] Inside loop -> check if the value of multipleOfN is less than 2*i.
5] If yes, multipleOfN = multipleOfN + multipleOfN. and continue to next iteration
6] If no, then i++

If multipleOfN becomes equal to 2*i then the loop gets exited .
And the value is returned,which is the smallest multiple of 2 and n.



Optimized Approach 1:
1) If n is even, return n 
2) Else return n*2

(
If a number is even, it means it is multiple of 2.
If it is odd, then the common multiple can be that number*2
)

code:
if(n%2 == 0){
return n;
}
else{
return n*2;
}

Optimized Approach 2:
code:
    return n << (n & 1);

1]Here, if the n is even,then (n&1) resolves to 0 .
2]so no left shift happens.So, simply value of n is returned.
3]And if n is odd, then (n&1) resolves to 1.
4]so the n is left shifted by 1 bit, which eventually means that the number is multiplied by 2. so, this new value is returned.

*/
