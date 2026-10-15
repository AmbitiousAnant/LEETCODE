class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int counts[101] = {0};
            int distinct = 0;
            
            for (int j = i; j < n; j++) {
                if (counts[nums[j]] == 0) {
                    distinct++;
                }
                counts[nums[j]]++;
                res += distinct * distinct;
            }
        }
        
        return res;
    }
};