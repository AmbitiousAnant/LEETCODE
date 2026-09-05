class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        vector<int> b(n);
        
        int m = nums[0];
        for(int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            a[i] = m;
        }
        
        int mi = nums[n - 1];
        for(int i = n - 1; i >= 0; i--) {
            mi = min(mi, nums[i]);
            b[i] = mi;
        }
        
        for(int i = 0; i < n; i++) {
            if(a[i] - b[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};