class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int &x : nums) {
            sum += x;
        }

        int cs = 0; // cumulative sum from left
        for (int i = 0; i < n; i++) {
            int ls = cs;
            int rs = sum - cs - nums[i];
            
            if (ls == rs) {
                return i;
            }

            cs += nums[i]; // move this outside the if
        }
        return -1;
    }
};
