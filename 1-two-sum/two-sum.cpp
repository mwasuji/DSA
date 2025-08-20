class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; // number -> index

        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int required = target - current;

            // Check if the "required" number already exists in map
            if (m.find(required) != m.end()) {
                return {i, m[required]};
            }

            // Store current number with its index
            m[current] = i;
        }

        return {-1, -1}; // not found
    }
};
