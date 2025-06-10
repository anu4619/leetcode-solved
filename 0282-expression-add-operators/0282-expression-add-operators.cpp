class Solution {
public:
    vector<string> result;

    void backtrack(string& num, int target, int pos, long eval, long multed, string expr) {
        if (pos == num.size()) {
            if (eval == target) {
                result.push_back(expr);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            
            if (i != pos && num[pos] == '0') break;

            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);

            if (pos == 0) {
               
                backtrack(num, target, i + 1, currNum, currNum, currStr);
            } else {
                backtrack(num, target, i + 1, eval + currNum, currNum, expr + "+" + currStr);
                backtrack(num, target, i + 1, eval - currNum, -currNum, expr + "-" + currStr);
                
                backtrack(num, target, i + 1, eval - multed + multed * currNum, multed * currNum, expr + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};