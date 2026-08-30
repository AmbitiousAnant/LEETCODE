class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        auto maxptr=max_element(nums.begin(),nums.end());
        int maxidx=maxptr-nums.begin();
        auto minptr=min_element(nums.begin(),nums.end());
        int minidx=minptr-nums.begin();
        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);
        int l=1+right;
        int r=n-left;
        int m=(1+left)+(n-right);
        return min({l,r,m});
       
    }
};