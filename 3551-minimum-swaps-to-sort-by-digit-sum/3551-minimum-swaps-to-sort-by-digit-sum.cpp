class Solution {
public:
    int getSum(int n) {
        int s = 0;
        while (n > 0) {
            s = s + (n % 10);
            n = n / 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        
        sort(target.begin(), target.end(), [this](int a, int b) {
            int sumA = getSum(a);
            int sumB = getSum(b);
            if (sumA == sumB) {
                return a < b;
            }
            return sumA < sumB;
        });
        
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                swaps++;
                
                int wrongNum = nums[i];
                int rightNum = target[i];
                int rightIdx = pos[rightNum];
                
                nums[i] = rightNum;
                nums[rightIdx] = wrongNum;
                
                pos[wrongNum] = rightIdx;
            }
        }
        
        return swaps;
    }
};