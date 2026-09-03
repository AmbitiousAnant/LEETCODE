class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int m = nums1[0];
        bool odd = false;
        
        for (int x : nums1) {
            if (x < m) {
                m = x;
            }
            if (x % 2 != 0) {
                odd = true;
            }
        }
        
        if (m % 2 != 0) {
            return true;
        } else {
            return !odd;
        }
    }
};