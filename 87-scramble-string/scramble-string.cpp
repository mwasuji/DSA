class Solution {
public:
    unordered_map<string, bool>mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();
        if(s2.size() != n || n == 1) return false; 
        string s = s1 + " " + s2;
        if(mp.find(s) != mp.end()) return mp[s];
        for(int i = 1; i < n; i++){
            bool x = (isScramble(s1.substr(0, i), s2.substr(0, i)) 
            && isScramble(s1.substr(i), s2.substr(i)));
            if(x) return mp[s] = true; 
            bool y = (isScramble(s1.substr(0, i), s2.substr(n-i)) 
            && isScramble(s1.substr(i), s2.substr(0, n-i)));
            if(y) return mp[s] = true; 
        }
        return mp[s] = false;
    }
};