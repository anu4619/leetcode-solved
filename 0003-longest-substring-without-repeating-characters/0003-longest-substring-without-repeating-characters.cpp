class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left=0;
        int maxLen=0;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            while(seen.count(c))
            {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[i]);
            maxLen=max(maxLen,i-left+1);
        }

        return maxLen;
    }
};