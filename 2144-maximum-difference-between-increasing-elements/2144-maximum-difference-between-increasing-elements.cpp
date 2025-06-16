class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int diff, maxDiff=-1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i]){
             diff=nums[j]-nums[i];
             maxDiff=max(diff,maxDiff);
                }
            
            }
        }

        return maxDiff==INT_MIN?-1:maxDiff;
    }
};