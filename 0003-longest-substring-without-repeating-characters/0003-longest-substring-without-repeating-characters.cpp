class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        vector<int> cnt(256, 0);
        
        for (int r = 0; r < s.length(); r++) {
            while (cnt[s[r]] > 0) {
                cnt[s[l]]--;
                l++;
            }
            
            cnt[s[r]]++;
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};