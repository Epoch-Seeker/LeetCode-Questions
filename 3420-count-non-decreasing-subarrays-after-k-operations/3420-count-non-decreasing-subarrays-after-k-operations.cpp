
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;
        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int cnt = 1;

            // Merge smaller values into current value
            while (!dq.empty() && dq.back().first < num) {
                auto [val, freq] = dq.back();
                dq.pop_back();

                cnt += freq;
                cost += 1LL * (num - val) * freq;
            }

            dq.push_back({num, cnt});

            // Reduce window if operations exceed k
            while (cost > k) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost -= val - nums[j];
                j--;

                if (freq > 1) {
                    dq.push_front({val, freq - 1});
                }
            }

            // All subarrays ending at j and starting from i to j
            // are valid
            ans += j - i + 1;
        }

        return ans;
    }
};
