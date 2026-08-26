class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hmm(nums.begin(),nums.end());
        
        int i=k;
        while(hmm.count(i)){
            i+=k;
        }
        return i;
    }
};