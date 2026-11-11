class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, true);
    }
    
    int helper(int n, bool leftToRight) {
        if (n == 1) {
            return 1;
        }
        if (leftToRight || n % 2 == 1) {
            return 2 * helper(n / 2, !leftToRight);
        }
        return 2 * helper(n / 2, !leftToRight) - 1;
    }
};