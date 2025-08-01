class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>&res, string& stack) {
        if(open == close && open == n) {
            res.push_back(stack);
            return;
        }
        if(open<n) {
            stack+='(';
            backtrack(open+1,close,n,res,stack);
            stack.pop_back();
        }
        if(close<open) {
            stack+=')';
            backtrack(open,close+1,n,res,stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
};