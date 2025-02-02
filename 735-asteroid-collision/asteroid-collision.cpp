class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            while (!st.empty() && ast < 0 && st.top() > 0) { 
                // Compare absolute values
                if (abs(ast) == st.top()) {  
                    st.pop(); // Both destroy each other
                    destroyed = true;
                    break;
                } else if (abs(ast) > st.top()) {  
                    st.pop(); // Destroy top asteroid, continue checking
                } else {
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(ast); // If asteroid survived, push to stack
            }
        }

        // Convert stack to vector (in correct order)
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
