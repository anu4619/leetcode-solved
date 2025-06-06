class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        
        for (int i = 0; i < s1.size(); ++i) {
            int p1 = find(s1[i] - 'a');
            int p2 = find(s2[i] - 'a');
            if (p1 != p2) {
    
                if (p1 < p2) parent[p2] = p1;
                else parent[p1] = p2;
            }
        }
        string result;
        for (char ch : baseStr) {
            result += char(find(ch - 'a') + 'a');
        }

        return result;
    }
};