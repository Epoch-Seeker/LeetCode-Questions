class Solution {
public:
    multiset<int> left, right;
    long long sumL = 0, sumR = 0;

    void balance() {
        while (left.size() > right.size() + 1) {
            int val = *left.rbegin();
            left.erase(prev(left.end()));
            sumL -= val;

            right.insert(val);
            sumR += val;
        }

        while (left.size() < right.size()) {
            int val = *right.begin();
            right.erase(right.begin());
            sumR -= val;

            left.insert(val);
            sumL += val;
        }
    }

    void add(int x) {
        if (left.empty() || x <= *left.rbegin()) {
            left.insert(x);
            sumL += x;
        } else {
            right.insert(x);
            sumR += x;
        }

        balance();
    }

    void remove(int x) {
        auto it = left.find(x);

        if (it != left.end()) {
            left.erase(it);
            sumL -= x;
        } else {
            it = right.find(x);
            right.erase(it);
            sumR -= x;
        }

        balance();
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumL
             + sumR - median * right.size();
    }

    long long solve(vector<long long>& cost, int idx, int k,
                    int x, vector<vector<long long>>& dp) {

        if (k == 0) return 0;

        if (idx >= cost.size()) return LLONG_MAX / 4;

        if (dp[idx][k] != -1) return dp[idx][k];

        long long skip = solve(cost, idx + 1, k, x, dp);

        long long take = cost[idx] +
                         solve(cost, idx + x, k - 1, x, dp);

        return dp[idx][k] = min(take, skip);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        if (1LL * x * k > n) return -1;

        left.clear();
        right.clear();
        sumL = sumR = 0;

        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        int m = cost.size();

        vector<vector<long long>> dp(
            m + 1, vector<long long>(k + 1, -1)
        );

        return solve(cost, 0, k, x, dp);
    }
};