class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result; // To store unique valid integers
    
    int n = digits.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                
                int a = digits[i];
                int b = digits[j];
                int c = digits[k];
                
                // Check leading zero
                if (a == 0) continue;
                
                // Check even number (last digit must be even)
                if (c % 2 != 0) continue;
                
                int num = a * 100 + b * 10 + c;
                result.insert(num);
            }
        }
    }
    
    return vector<int>(result.begin(), result.end());
    }
};