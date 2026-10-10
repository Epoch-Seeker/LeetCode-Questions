
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long sum = 0, high = 0;
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);

        for (int i = 0; i < n; i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff[i] = d;
            high = max(high, d);
            sum += d;
        }

        if (sum <= k) return 0;

        long long low = 0, temp = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (long long d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k) {
                temp = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long used = 0, ans = 0;

        for (long long& d : diff) {
            if (d > temp)
                used += d - temp;

            d = min(d, temp);
            ans += d * d;
        }

        long long remain = k - used;

        // Reduce remaining differences equal to temp by one.
        for (long long& d : diff) {
            if (remain == 0) break;

            if (d == temp && d > 0) {
                ans -= d * d;
                d--;
                ans += d * d;
                remain--;
            }
        }

        return ans;
    }
};
