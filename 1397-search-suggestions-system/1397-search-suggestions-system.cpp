class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix;

        for (char c : searchWord) {
            prefix += c;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> suggestions;

            for (int i=0;i<3 && it+i!=products.end(); ++i) {
                string& s = *(it + i);
                if (s.find(prefix) != 0) break;
                suggestions.push_back(s);
            }
            result.push_back(suggestions);
        }
        return result;
    }
};