class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int maskedNumber = 0;
        if(m == 0){
            return 1;
        }
        while(m!=0){
            m = m>>1;
            maskedNumber = (maskedNumber<<1)|1;
        }
        
        int complement = (~n)&maskedNumber;   
        return complement;
    }
};