class Solution {
public:
    bool doesAliceWin(string s) {

        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cnt++;
        }

        if(cnt==0) return false;

        return true;
        
    }
};