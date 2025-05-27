class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // Ensure the stack is not empty before accessing top
                if (st.empty()) return false;
                
                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched parentheses
                }
            }
        }
        
        // Stack should be empty if all parentheses are valid
        return st.empty();
    }
};
