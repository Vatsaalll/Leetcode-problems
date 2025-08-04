#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // Map to count the number of each fruit type in the window
        int maxLen = 0, left = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            
            // If we have more than 2 types of fruits, shrink the window from the left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
