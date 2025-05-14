class Solution {
public:
    string convert(string s, int numRows) {
       
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            // Change direction when reaching top or bottom row
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows
        string result;
        for (const string &row : rows)
            result += row;

        return result;
    }
};