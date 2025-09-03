class Solution {
public:
    const long long mod = 1e9 + 7;

    long long power(long long n, long long m) {
        long long res = 1;
        n %= mod;
        while (m > 0) {
            if (m & 1) res = (res * n) % mod;
            n = (n * n) % mod;
            m >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        return (power(5, even) * power(4, odd)) % mod;
    }
};
