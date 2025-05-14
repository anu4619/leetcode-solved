class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char current = s[end];

            if (lastSeen.count(current) && lastSeen[current] >= start) {
                // Move the start to the right of the last occurrence
                start = lastSeen[current] + 1;
            }

            lastSeen[current] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};