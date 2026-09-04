class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int max_val = nums[0];
            for (int j = 0; j <= i; j++) {
                if (nums[j] > max_val) {
                    max_val = nums[j];
                }
            }
            
            int min_val = nums[i];
            for (int j = i; j < n; j++) {
                if (nums[j] < min_val) {
                    min_val = nums[j];
                }
            }
            
            if (max_val - min_val <= k) {
                return i;
            }
        }
        return -1;
    }
};