class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                char topChar = st.top();
                st.pop();
                
                if (c == ')' && topChar != '(') return false;
                if (c == '}' && topChar != '{') return false;
                if (c == ']' && topChar != '[') return false;
            }
        }
        
        return st.empty();
    }
};