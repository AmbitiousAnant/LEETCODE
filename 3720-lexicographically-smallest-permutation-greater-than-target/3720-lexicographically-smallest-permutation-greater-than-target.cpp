class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        int n = s.length();
        int limit = 0;
        unordered_map<char, int> temp = m;
        while (limit < n && temp[target[limit]] > 0) {
            temp[target[limit]]--;
            limit++;
        }
        
        int start = min(limit, n - 1);
        for (int i = start; i >= 0; --i) {
            unordered_map<char, int> avail = m;
            for (int j = 0; j < i; ++j) {
                avail[target[j]]--;
            }
            
            char next_char = '{';
            for (auto pair : avail) {
                if (pair.second > 0 && pair.first > target[i] && pair.first < next_char) {
                    next_char = pair.first;
                }
            }
            
            if (next_char != '{') {
                string ans = target.substr(0, i);
                ans += next_char;
                avail[next_char]--;
                
                string left = "";
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (avail[c] > 0) {
                        left += string(avail[c], c);
                    }
                }
                return ans + left;
            }
        }
        return "";
    }
};