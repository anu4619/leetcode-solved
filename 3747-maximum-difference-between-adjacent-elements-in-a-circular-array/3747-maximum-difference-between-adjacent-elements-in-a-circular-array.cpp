class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
    int maxDiff = 0;

    for (int i = 0; i < n; ++i) {
        int nextIndex = (i + 1) % n;
        int diff = abs(nums[i] - nums[nextIndex]);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
    }
};