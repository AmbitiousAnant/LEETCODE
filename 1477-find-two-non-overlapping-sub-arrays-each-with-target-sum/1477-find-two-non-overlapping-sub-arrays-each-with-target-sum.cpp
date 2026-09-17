class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int not_found = n + 1; 
        
        vector<int> best_len(n, not_found); 
        
        int ans = not_found;
        int left = 0;
        int current_sum = 0;
        int min_so_far = not_found;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            if (current_sum == target) {
                int current_len = right - left + 1;
                
                if (left > 0 && best_len[left - 1] != not_found) {
                    ans = min(ans, current_len + best_len[left - 1]);
                }
                
                min_so_far = min(min_so_far, current_len);
            }
            
            best_len[right] = min_so_far;
        }
        
        if (ans > n) {
            return -1;
        } else {
            return ans;
        }
    }
};