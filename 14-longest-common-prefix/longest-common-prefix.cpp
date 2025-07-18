class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Handle empty input
        
        string ans = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    match = false;
                    break;
                }
            }

            if (!match) {
                break;
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

