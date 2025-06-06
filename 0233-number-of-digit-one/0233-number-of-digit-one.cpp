class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1;
        int res = 0;
        int high = n / 10, curr = n % 10, low = 0;

        while (high != 0 || curr != 0) {
            if (curr == 0) {
                res += high * digit;
            } else if (curr == 1) {
                res += high * digit + low + 1;
            } else {
                res += (high + 1) * digit;
            }

            low = curr * digit + low;
            curr = high % 10;
            high /= 10;
            digit *= 10;
        }

        return res;
    }
};