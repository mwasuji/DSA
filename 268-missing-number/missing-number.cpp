class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            ans ^=nums[i];

        }
        int n =nums.size();
        for(int i=0;i<=n; i++){
            ans^=i;
        }

return ans;
    }
};