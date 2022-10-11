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