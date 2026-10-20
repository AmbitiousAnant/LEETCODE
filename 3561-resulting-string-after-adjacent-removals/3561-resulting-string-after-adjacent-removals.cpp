class Solution {
public:
    string resultingString(string s) {
        string ans = ""; 
        
        for (int i = 0; i < s.length(); i++) {
            if (!ans.empty()) {
                int diff = abs(ans.back() - s[i]);
                
                if (diff == 1 || diff == 25) {
                    ans.pop_back(); 
                    continue; 
                }
            }
            
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};