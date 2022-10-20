class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start^goal; // here the answer will be a number, who has only the number of set bits which needs to be flipped to convert the Number
        int count = 0;
        
        //counting number of set bits in the xorResult
        int i = 0;
        while(xorResult!=0){
            if(xorResult&1){
                count++;
            }
            xorResult = xorResult>>1;
            i++;
        }
        return count;
        
    }
};


/*
Approach: 
1] 10 xor 7 
ans = 1010 xor 0111 
ans = 1101

2] count the number of set bits in ans.
(3 in this case)
3] return the count
*/