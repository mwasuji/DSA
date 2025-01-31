class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s[0] != 'a') return false;  // Ensure first character is 'a'

        stack<char> st;
        for (char ch : s) {  // Iterate over each character
            if (ch == 'a') {
                st.push(ch);
            } else if (ch == 'b') {
                if (!st.empty() && st.top() == 'a') {
                    st.push(ch);
                } else {
                    return false;
                }
            } else if (ch == 'c') {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();  // Remove 'b'
                    if (!st.empty() && st.top() == 'a') {
                        st.pop();  // Remove 'a'
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;  // Invalid character
            }
        }
        
        return st.empty();  // Valid if stack is empty at the end
    }
};
