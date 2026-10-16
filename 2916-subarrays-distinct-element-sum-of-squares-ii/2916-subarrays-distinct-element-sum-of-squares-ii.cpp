class Solution {
    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        seg[node].sqSum += 2 * val * seg[node].sum
                         + val * val * len;

        seg[node].sum += val * len;
        seg[node].lazy += val;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        long long val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum = seg[node * 2].sum
                      + seg[node * 2 + 1].sum;

        seg[node].sqSum = seg[node * 2].sqSum
                        + seg[node * 2 + 1].sqSum;
    }

public:
    int mod = 1e9+7;
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last.count(nums[j])
                     ? last[nums[j]]
                     : -1;

            update(1, 0, n - 1, prev + 1, j, 1);

            ans += seg[1].sqSum;
            ans %= mod;
            last[nums[j]] = j;
        }

        return (int)ans;
    }
};