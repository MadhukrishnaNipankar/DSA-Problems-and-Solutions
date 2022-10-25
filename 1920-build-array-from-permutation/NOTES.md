**Explanation for O(1) space complexity**
​
*Lets first see generally what should be done.*
​
1. We need to store 2 values in one place, so we will use math **(quotient and remainder)**
​
2. Let,** size of array **= n
original number = a
final number = b
​
3. So we will store **a = a + n*b**
​
4. On taking** a%n**, we will get a
On doing **a/n**, we will get b
​
5. Here the b that we are using is actually an a and there is a chance that it might be an a that is updated (final number)
To get a from a, we use a%n
So, here it will be b%n
​
6. Finally, our equation becomes **a=a +n(b%n)**
​
7. In the question **a=nums[i] and b=nums[nums[i]]**
​
8. So finally, the equation becomes
**nums[i] = nums[i] + n * (nums[nums[i]]%n)**
​
​
​
​
​
Refer Link for  explanation:- https://leetcode.com/problems/build-array-from-permutation/discuss/1692310/Easy-explanation-for-O(1)-space-complexity