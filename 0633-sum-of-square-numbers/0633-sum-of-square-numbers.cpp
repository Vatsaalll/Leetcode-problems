#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = static_cast<long long>(std::sqrt(c));
        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                ++left;
            } else {
                --right;
            }
        }
        return false;
    }
};