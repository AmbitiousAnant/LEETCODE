class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        string m = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty()) {
                int diff = abs(st.top() - s[i]);
                
                if(diff == 1 || diff == 25) {
                    st.pop(); 
                    continue; 
                }
            }
            
            st.push(s[i]);
        }
        
        while(!st.empty()){
            m += st.top();
            st.pop();
        }
        
        reverse(m.begin(), m.end());
        
        return m;
    }
};