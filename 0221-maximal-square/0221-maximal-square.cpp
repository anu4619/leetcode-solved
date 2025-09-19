class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int digonal=dp[i+1][j+1];
                int dowm=dp[i+1][j];

                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min(right,(min(digonal,dowm)));
                    maxi=max(dp[i][j],maxi);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }

        return maxi*maxi;
    }
};