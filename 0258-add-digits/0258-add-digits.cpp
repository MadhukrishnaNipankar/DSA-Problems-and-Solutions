class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        
        int sum = 0, temp = num;
        //loop until temp is of more than one digit
        while(temp > 9){
            sum +=(num%10);
            num/=10; 
            
            /*if at some point, we get sum of all digits,then eventually, 
              num becomes 0. so, to sum the digits of the sum variable we got                 here, we reinitialize num and temp = sum
            */
            if(num == 0){
                num = sum;
                temp = sum;
                sum = 0;
            }
        }
        return temp;
    }
};
