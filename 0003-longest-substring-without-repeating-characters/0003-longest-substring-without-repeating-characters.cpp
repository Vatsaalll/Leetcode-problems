class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> setesh;
        int l = 0;
        int res = 0;

        for(int r = 0;r<s.size();r++) {
            while(setesh.find(s[r]) != setesh.end()) {
                setesh.erase(s[l]);
                l++;
            }
            setesh.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
