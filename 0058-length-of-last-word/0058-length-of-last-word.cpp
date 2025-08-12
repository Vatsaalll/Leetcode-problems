class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int ans=0;
        bool counting = false;
        for(int i =n-1;i>=0;i--) {
            if(s[i] != ' ') {
                counting = true;
                ans++;
            }
            else if(counting) {
                break;
            }

        }
        return ans;
    }
};