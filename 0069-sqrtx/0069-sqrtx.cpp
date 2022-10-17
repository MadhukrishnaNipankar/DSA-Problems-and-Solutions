class Solution {
public:
    long calcPower(int m, int n){
        long power = m, i = 0;
        while(i<n-1){
            power *= power;
            i++;
        }
        return power;
    }
    
    int mySqrt(int x) {
        if(x==2)return 1;
        if(x==0)return 0;
        long i = 1;
        while(i<x){
            long square = calcPower(i,2);
            if(square == x){
                return i;
            }
            else if(square > x){
                return i-1;
            }
            i++;
        }
        return i;
    }
};
