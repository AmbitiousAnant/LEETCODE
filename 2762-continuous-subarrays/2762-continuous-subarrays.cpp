class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        long long totalSubarrays = 0;
        int left = 0;
        deque<int> maxQ; 
        deque<int> minQ;
        
        for (int right = 0; right < nums.size(); ++right) {
            while (!maxQ.empty() && maxQ.back() < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[right]);
            while (!minQ.empty() && minQ.back() > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(nums[right]);
            while (!maxQ.empty() && !minQ.empty() && maxQ.front() - minQ.front() > 2) {
                if (maxQ.front() == nums[left]) {
                    maxQ.pop_front();
                }
                if (minQ.front() == nums[left]) {
                    minQ.pop_front();
                }
                left++;
            }
            totalSubarrays += (right - left + 1);
        }
        
        return totalSubarrays;
    }
};