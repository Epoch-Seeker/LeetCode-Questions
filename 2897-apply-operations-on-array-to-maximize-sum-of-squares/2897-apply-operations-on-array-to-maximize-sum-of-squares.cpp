class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32 , 0);

        for(int x : nums){
            for(int i = 0; i< 32 ; i++){
                if(x & (1 << i)){
                    bits[i]++;
                }
            }
        }

        long long ans = 0;

        for(int i=0;i < k ; i++){
            long long x = 0;

            for(int b=0 ; b < 32 ; b++){
                if(bits[b] > 0){
                    x |= (1LL << b);
                    bits[b]--;
                }
            }

            ans += (x*x);
            ans %= MOD;

        }

        // for(int i: bits){
        //     cout<<i<<" ";
        // }
        return ans;
    }
};