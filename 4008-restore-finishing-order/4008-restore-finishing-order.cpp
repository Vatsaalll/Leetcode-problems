class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        for (int id : order) {
            for (int friendId : friends) {
                if (id == friendId) {
                    result.push_back(id);
                    break;
                }
            }
        }
        return result;
    }
};