class Solution {
public:
    bool isRotation(vector<int>& a, int l, int r,
                    vector<int>& b) {
        int k = r - l;
        vector<int> pi(k, 0);

        for (int i = 1; i < k; i++) {
            int j = pi[i - 1];

            while (j > 0 && b[l + i] != b[l + j])
                j = pi[j - 1];

            if (b[l + i] == b[l + j])
                j++;

            pi[i] = j;
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int x = a[l + i % k];

            while (j > 0 && x != b[l + j])
                j = pi[j - 1];

            if (x == b[l + j])
                j++;

            if (j == k)
                return true;
        }

        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                if (!isRotation(nums, i, i + k, sortedNums)) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};