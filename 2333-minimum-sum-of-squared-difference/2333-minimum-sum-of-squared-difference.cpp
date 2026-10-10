class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long sum = 0 , high = 0;
        vector<long long> diff(n);
        long long k = (long long)k1 + k2;

        for(int i=0;i<n;i++){
            long long d = abs(nums1[i] - nums2[i]);
            high = max(high , d);
            diff[i] = d;
            sum += d;
        }

        if(sum <= k)return 0;

        long long low = 0;

        long long temp = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            long long need = 0;

            for(int d : diff){
                if(d > mid)need += (d - mid);
            }

            if(need <= k){
                temp = mid;
                high = mid - 1;
            }else low = mid + 1;
        }

        long long used = 0 , ans = 0;

        for(auto& d : diff){
            if(d > temp){
                used += (d - temp);
            }
            d = min(d , temp);
            ans += d*d;
        }

        long long remain = k - used;
        if(remain == 0)return ans;

        priority_queue<long long> pq;

        for(int d : diff)pq.push(d);

        while(remain--){

            long long d = pq.top();
            pq.pop();

            if(d == 0)return 0;

            ans -= d*d;
            ans += (d-1)*(d-1);

            pq.push(d-1);

        }

        return ans;

    }
};