class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        
        // while(e>s)
        // {
        //     if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
        //         return nums[mid];
        //     }
        //     else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
        //         s=mid+1;
        //     }
        //     else{
        //         e=mid-1;
        //     }
        // }
        // return -1;
        while(e>s)
        {int mid=s+(e-s)/2;
            if (nums[mid]<nums[mid+1])
            
            {
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
};