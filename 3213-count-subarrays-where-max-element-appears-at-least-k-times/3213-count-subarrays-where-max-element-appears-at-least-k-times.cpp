class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = 0;
    for (int n :nums) {
      maxElement = max(maxElement, n);
    }

    long long count = 0;
    int l = 0;
    int n = nums.size();
    int maxFound = 0;

    for (int r = 0; r < n; r++) {
      if (nums[r] == maxElement) maxFound++;

      while (maxFound == k) {
        count += n - r;
        if (nums[l] == maxElement) maxFound--;
        l++;
      }
    }

    return count;
    }
};