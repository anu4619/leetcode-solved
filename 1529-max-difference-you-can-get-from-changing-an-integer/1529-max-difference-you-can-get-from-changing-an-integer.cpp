class Solution {
public:
int replaceDigit(int num, int x, int y) {
    string s = to_string(num);
    for (char &ch : s) {
        if (ch == ('0' + x))
            ch = ('0' + y);
    }

    if (s[0] == '0') return -1;

    return stoi(s);
}
    int maxDiff(int num) {
        int maxNum = num;
    int minNum = num;
    for (int x = 0; x <= 9; x++) {
        int a = replaceDigit(num, x, 9);
        if (a != -1)
            maxNum = max(maxNum, a);
    }
    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 1; y++) { 
            int b = replaceDigit(num, x, y);
            if (b != -1 && b != 0)
                minNum = min(minNum, b);
        }
    }

    return maxNum - minNum;
    }
};