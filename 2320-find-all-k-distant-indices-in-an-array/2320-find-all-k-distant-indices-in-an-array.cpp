class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result;
        int n=nums.size();
for(int j=0;j<n;++j) {
            if (nums[j]==key) {
                int left=max(0,j-k);
                int right = min(n-1,j+k);
                for(int i=left; i<=right;++i) {
                    result.insert(i);
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};