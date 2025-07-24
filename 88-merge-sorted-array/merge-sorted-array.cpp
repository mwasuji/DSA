class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> nums3(n + m); // Allocate enough space
        int left = 0, right = 0, index = 0;

        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                nums3[index++] = nums1[left++];
            } else {
                nums3[index++] = nums2[right++];
            }
        }

        while (left < n) {
            nums3[index++] = nums1[left++];
        }

        while (right < m) {
            nums3[index++] = nums2[right++];
        }

        // Copy back to nums1
        for (int i = 0; i < n + m; i++) {
            nums1[i] = nums3[i];
        }
    }
};