class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long leng = 1;
        vector<long long> leng1;
        leng1.push_back(leng);

        for(int op : operations) {
            if (leng > k) break;
            if(op == 0 || op==1) {
                leng *=2;
            }
            leng1.push_back(leng);
        }

        long long curr = k;
        int opidx = leng1.size() - 2;
        char curchar = 'a';

        while(opidx>=0) {
            long long half = leng1[opidx];
            if(curr > half) {
                curr -= half;
                if(operations[opidx]==1) {
                    curchar = 'a'+(curchar-'a'+1) %26;
                }
            }
            opidx--;


        }
        return curchar; 
    }
};