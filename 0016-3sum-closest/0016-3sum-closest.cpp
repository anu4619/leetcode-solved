class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closestSum if closer to target
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    // Exact match
                    return sum;
                }
            }
        }

        return closestSum;
    }
};