class Solution {
    private:
    void solve(vector<int> output,vector<vector<int>>& ans,int index,vector<int>& nums){
        //base case
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude
        solve(output,ans,index+1,nums);

        // include
        int e=nums[index];
        output.push_back(e);
        solve(output,ans,index+1,nums);

        // output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index=0;
        solve(output,ans,index,nums);
      return ans;
    }
};