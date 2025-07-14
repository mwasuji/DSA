class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;  // If needle is an empty string, return 0

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            for (; j < m; j++) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
            if (j == m) {
                return i;  // Found the needle, return its start index
            }
        }
        return -1;  // Needle not found
    }
};

