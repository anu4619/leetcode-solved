class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
    

    result.push_back(words[0]); 
    int lastGroup = groups[0];

    for (size_t i = 1; i < words.size(); ++i) {
        if (groups[i] != lastGroup) {
            result.push_back(words[i]);
            lastGroup = groups[i];
        }
    }

    return result;
    }
};