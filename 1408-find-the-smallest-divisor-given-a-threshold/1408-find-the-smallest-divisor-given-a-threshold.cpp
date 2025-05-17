class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int total = 0;

            for (int num:nums) {
                total+=(num+mid-1)/mid;
            }

            if (total <= threshold) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;   
            }
        }

        return result;
    }
};