class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> result;
        for(int i =0;i<n;i++)
        {string s=words[i];
            for(char c:s)
            {
if (x==c)
{ 
    result.push_back(i);
    break;
}
            }
        }

        return result;
    }
};