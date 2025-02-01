class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> answer(n, -1); // Initialize the result with -1
        stack<int> st; // Stack to store indices of cars

        // Iterate from the last car to the first car
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty()) {
                int j = st.top();
                
                // If the car at the top of the stack is moving at the same or a slower speed, it will never collide
                if (cars[i][1] <= cars[j][1]) {
                    st.pop();
                    continue;
                }

                // Calculate the collision time
                double coltime = (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);

                // If the top car has no collision or the calculated time is valid, set the answer and break
                if (answer[j] == -1 || coltime <= answer[j]) {
                    answer[i] = coltime;
                    break;
                }

                // Otherwise, pop the top car and continue checking
                st.pop();
            }
            
            // Push the current car index onto the stack
            st.push(i);
        }

        return answer; // Return the final collision times
    }
};
