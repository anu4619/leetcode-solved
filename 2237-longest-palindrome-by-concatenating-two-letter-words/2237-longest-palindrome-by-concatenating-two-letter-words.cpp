class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
    int length = 0;
    bool hasCenter = false;

    for (const string& word:words) {
        string reversed= word;
        swap(reversed[0],reversed[1]);
        if (freq[reversed]>0) {
            freq[reversed]--;
            length+=4;
        } else {
            freq[word]++;
        }
    }
    for (auto& [word,count]:freq) {
        if (word[0]==word[1] && count > 0) {
            hasCenter = true;
            break;
        }
    }

    return hasCenter ? length + 2 : length;
    }
};