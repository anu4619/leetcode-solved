class Solution {
public:
const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
         vector<long long> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'a']++;
    }


    for (int step = 0; step < t; ++step) {
        vector<long long> newFreq(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (i == 25) {
                
                newFreq[0] = (newFreq[0] + freq[25]) % MOD;
                newFreq[1] = (newFreq[1] + freq[25]) % MOD;
            } else {
            
                newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
            }
        }

        freq = newFreq;
    }

    long long result = 0;
    for (int i = 0; i < 26; ++i) {
        result = (result + freq[i]) % MOD;
    }

    return (int)result;
    }
};