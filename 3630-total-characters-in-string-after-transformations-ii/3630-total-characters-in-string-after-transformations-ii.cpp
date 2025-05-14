#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    const int N = 26;
    using Matrix = vector<vector<long long>>;

    // Matrix multiplication
    Matrix multiply(const Matrix &a, const Matrix &b) {
        Matrix res(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                if (a[i][k])
                    for (int j = 0; j < N; ++j)
                        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
        return res;
    }

    // Matrix exponentiation
    Matrix power(Matrix base, int exp) {
        Matrix res(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i)
            res[i][i] = 1;
        while (exp) {
            if (exp % 2)
                res = multiply(res, base);
            base = multiply(base, base);
            exp /= 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums)
 {
        // Build transition matrix
        Matrix T(N, vector<long long>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int nextChar = (i + j) % 26;
                T[nextChar][i] = (T[nextChar][i] + 1) % MOD;
            }
        }

        // Raise matrix to the t-th power
        Matrix Tt = power(T, t);

        // Initial frequency vector
        vector<long long> freq(N, 0);
        for (char ch : s)
            freq[ch - 'a']++;

        // Multiply T^t with freq vector
        vector<long long> result(N, 0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                result[i] = (result[i] + Tt[i][j] * freq[j]) % MOD;

        // Sum up the final frequencies
        long long total = 0;
        for (int i = 0; i < N; ++i)
            total = (total + result[i]) % MOD;

        return total;
    }
};
