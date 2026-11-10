#include<iostream>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.back();
        vector<int> nums2(n);
        for(int i=0; i < n; i++){
            nums2[i]=i;
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=nums2[j]){
                return nums2[j];
            }
            
        }
        return n+1;
    }
};