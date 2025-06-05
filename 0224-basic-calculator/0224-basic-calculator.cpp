class Solution {
public:
    int calculate(string s) {
         int res = 0;
        int num = 0;
        int sign = 1;  // 1 for '+', -1 for '-'
        stack<int> st;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop(); // sign
                res += st.top(); st.pop(); // previous result
            }
        }

        res += sign * num; // add the last number
        return res;
    }
};