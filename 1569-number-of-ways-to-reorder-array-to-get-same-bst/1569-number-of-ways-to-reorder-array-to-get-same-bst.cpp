class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long fact[1001];
    long long invFact[1001];

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    void precompute(int n) {
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r) {
        return fact[n] * invFact[r] % MOD
             * invFact[n - r] % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = nCr(n - 1, left.size());

        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        precompute(nums.size());

        return (solve(nums) - 1 + MOD) % MOD;
    }
};