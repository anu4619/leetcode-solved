class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
    vector<int> count(n + 1, 0);
    for (auto& q : queries) {
        int l = q[0], r = q[1];
        count[l]++;
        if (r + 1 < n) {
            count[r + 1]--;
        }
    }
    for (int i = 1; i < n; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        if (count[i] < nums[i]) {
            return false;
        }
    }

    return true;
    }
};