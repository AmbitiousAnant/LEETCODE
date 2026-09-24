class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int digitSum = 0;
            while (currentNumber > 0) {
                digitSum += currentNumber % 10; 
                currentNumber /= 10;            
            }
            if (digitSum == i) {
                return i; 
            }
        }
        return -1;
    }
};