class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 0;

    // Step 1: Precompute width of 1s in each row
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = (mat[i][j] == 0) ? 0 : (j == 0 ? 1 : dp[i][j - 1] + 1);
        }
    }

    // Step 2: For each cell, go upward and count submatrices
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int minWidth = dp[i][j];
            for (int k = i; k >= 0 && minWidth > 0; --k) {
                minWidth = min(minWidth, dp[k][j]);
                res += minWidth;
            }
        }
    }

    return res;
    }
};