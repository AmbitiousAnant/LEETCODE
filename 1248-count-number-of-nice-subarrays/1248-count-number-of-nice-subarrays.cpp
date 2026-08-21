class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0;
        int odds = 0;
        
        for (int num : nums) {
            odds += num % 2;
            if (counts.count(odds - k)) {
                ans += counts[odds - k];
            }
            counts[odds]++;
        }
        
        return ans;
    }
};