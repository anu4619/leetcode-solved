class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i:nums)
        {
            int j=(int)log10(i)+1;
            if(j%2==0)
            {
                count++;
            }
        }
        return count;
    }
};