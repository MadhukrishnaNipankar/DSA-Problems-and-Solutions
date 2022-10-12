class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){ 
            //checking if the last digit is one.
            if(n&1){
                count++;
            }
            n>>=1; //right shift
        }
        return count;
    }
};

/*
My Approach(The above solution):
1]check if the last digit of the given number is one. i.e suppose we perform (Bitwise &) operation on the number with 1. If the result is 1,
it means the last bit of the number is 1, else if the result is 0, then the last bit is 0.

2]if we find it to be 1, increase the count of 1.
3] do right shift operation on the number with 1, so that the last digit gets eliminated.
4] continue the above steps until number becomes 0.
5] return count

*/
