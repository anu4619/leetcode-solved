class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            expandAroundCenter(s, i, i, start, maxLen);     // Odd-length
            expandAroundCenter(s, i, i + 1, start, maxLen); // Even-length
        }

        return s.substr(start, maxLen);
    }


    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
    }
}};