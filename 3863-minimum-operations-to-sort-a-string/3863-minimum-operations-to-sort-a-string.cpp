class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        int ok = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[i-1]) {
                ok = 0;
                break;
            }
        }
        if(ok) return 0;
        
        if(n == 2) return -1;
        
        int mn = s[0];
        int mx = s[0];
        for(int i = 0; i < n; i++) {
            if(s[i] < mn) mn = s[i];
            if(s[i] > mx) mx = s[i];
        }
        
        if(s[0] == mn || s[n-1] == mx) return 1;
        
        int c1 = 1;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == mn) {
                c1 = 0;
                break;
            }
        }
        
        int c2 = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == mx) {
                c2 = 0;
                break;
            }
        }
        
        if(c1 && c2) return 3;
        
        return 2;
    }
};