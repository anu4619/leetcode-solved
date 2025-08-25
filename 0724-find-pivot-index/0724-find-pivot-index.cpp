class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> rSum(n,0),lSum(n,0);

        for(int i=1;i<n;i++)
        {
            lSum[i]=lSum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            rSum[i]=rSum[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            if(rSum[i]==lSum[i])
            {
                return i;
            }
           
        }
        return -1;
    }
};