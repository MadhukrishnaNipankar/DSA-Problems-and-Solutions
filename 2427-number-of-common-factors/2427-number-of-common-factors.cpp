class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0, i = 1,smallNo = (a<b)?a:b;
        while(i<=smallNo){
            if((a%i == 0)&&(b%i == 0)){
                count++;
            }
            i++;
        }
        return count;
    }
};