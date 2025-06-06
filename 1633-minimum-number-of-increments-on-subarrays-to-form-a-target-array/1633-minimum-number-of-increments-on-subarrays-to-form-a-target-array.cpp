class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ops = target[0];
    for (int i = 1; i < target.size(); ++i) {
        if (target[i] > target[i - 1]) {
            ops += target[i] - target[i - 1];
        }
    }
    return ops;
    }
};