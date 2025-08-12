class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> v(n, 1); // 1 means prime
        v[0] = v[1] = 0;     // 0 and 1 are not prime

        for (int i = 2; i * i < n; ++i) {
            if (v[i] == 1) {
                for (int val = i * i; val < n; val += i) {
                    v[val] = 0; // mark non-primes
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (v[i]) cnt++;
        }
        return cnt;
    }
};
