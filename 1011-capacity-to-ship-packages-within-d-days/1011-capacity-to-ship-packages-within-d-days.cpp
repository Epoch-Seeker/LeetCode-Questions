class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());

        int high = accumulate(weights.begin() , weights.end() , 0);

        // int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low)/2;

            // check whether mid can be our ans or not

            int need_of_days = 1;
            int w_loaded = 0;
            for(auto i : weights){
                if(w_loaded + i > mid){
                    need_of_days++;
                    w_loaded = i;
                }
                else 
                    w_loaded += i;
            }

            if(need_of_days <= days){
                // ans = mid;
                high = mid -1;
            }
            else low = mid + 1;
        }

        return low;
    }
};