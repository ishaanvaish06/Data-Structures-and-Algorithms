#include <vector>

class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        if (k < 0 || k >= n) return 0;

        long long MOD = 1e9 + 7;

        // Calculate (n-1)Ck
        long long combinations = nCr(n - 1, k, MOD);

        // Result is 2 * (n-1)Ck
        return (2 * combinations) % MOD;
    }

private:
    long long nCr(int n, int r, long long mod) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;

        std::vector<long long> dp(r + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = std::min(i, r); j > 0; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[r];
    }
};