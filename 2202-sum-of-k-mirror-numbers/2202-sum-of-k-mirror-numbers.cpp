class Solution {
public:
   bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += char('0' + (num % k));
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // Generate palindromes level by level
        for (int length = 1; count < n; length++) {
            int halfLength = (length + 1) / 2;
            long long start = pow(10, halfLength - 1), end = pow(10, halfLength);
            for (long long i = start; i < end && count < n; ++i) {
                string firstHalf = to_string(i);
                string full;
                if (length % 2 == 0) {
                    full = firstHalf + string(firstHalf.rbegin(), firstHalf.rend());
                } else {
                    full = firstHalf + string(firstHalf.rbegin() + 1, firstHalf.rend());
                }

                long long num = stoll(full);
                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }
};