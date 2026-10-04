class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        deque<int> q;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!q.empty() && q.front() > 2 * i + 2) {
                q.pop_front();
            }
            
            if (2 * i + 2 >= n) {
                dp[i] = prices[i];
            } else {
                dp[i] = prices[i] + dp[q.front()];
            }
            
            while (!q.empty() && dp[q.back()] >= dp[i]) {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        return dp[0];
    }
};