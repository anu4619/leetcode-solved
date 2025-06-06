class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
    
    int n = matrix[0].size();
    
    int low = 0, high = m * n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_value = matrix[mid / n][mid % n];
        
        if (mid_value == target)
            return true;
        else if (mid_value < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return false;
    }
};