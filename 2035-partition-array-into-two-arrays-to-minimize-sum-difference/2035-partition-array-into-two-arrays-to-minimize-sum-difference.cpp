class Solution {
public:
    void generate(vector<int>& nums , int l , int r, vector<vector<int>>& v , int sum , int sz){

        if(l == r){
            v[sz].push_back(sum);
            return ;
        }
        
        // include the number
        generate(nums , l+1 , r , v , sum + nums[l] , sz + 1);
        // exclude
        generate(nums , l+1 , r , v , sum , sz);

    }
    int minimumDifference(vector<int>& nums) {
        int tot_sum = accumulate(nums.begin() , nums.end() , 0);
        int N = nums.size();
        int n = N/2;
        vector<vector<int>> left(n+1) , right(n+1);
        generate(nums , 0 , n , left , 0 , 0);
        generate(nums , n , N , right , 0 , 0);

        for(auto& v : right){
            sort(v.begin() , v.end());
        }

        int ans = INT_MAX;

        for(int i =0 ; i<=n ; i++){
            int need = n-i;
            for(auto a : left[i]){
                int b = (tot_sum - (2*a))/2;

                auto itr = lower_bound(right[need].begin() , right[need].end() , b);

                if(itr != right[need].end()){
                    ans = min(ans , abs(2*(a+ *itr) - tot_sum));
                }

                if(itr !=  right[need].begin()){
                    itr--;
                    ans = min(ans , abs(2*(a+ *itr) - tot_sum));
                }

            }
        }

        return ans;
    }
};