class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        
        int sum = 0, temp = num;
        while(temp > 9){
            sum +=(num%10);
            num/=10; 
            if(num == 0){
                num = sum;
                temp = sum;
                sum = 0;
            }
        }
        return temp;
    }
};

