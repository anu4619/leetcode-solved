class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
    if (n < 3) return false;

    stack<int> st;
    int third = INT_MIN;  // This will store the maximum value of nums[k] encountered so far

    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i) {
        // If we find a number less than third, it means we found the pattern nums[i], nums[j], nums[k]
        if (nums[i] < third) return true;

        // Update third by maintaining the largest element in stack that can form nums[k]
        while (!st.empty() && st.top() < nums[i]) {
            third = st.top();
            st.pop();
        }

        // Push the current number onto the stack as a potential candidate for nums[j]
        st.push(nums[i]);
    }

    return false;
    }
};