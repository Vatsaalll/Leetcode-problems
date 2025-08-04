#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> basket;
        int left = 0;
        int n = fruits.size();
        
        for (int right = 0; right < n; right++) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};