class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = (long long)m*k ;
        
        if(val > bloomDay.size())return -1;

        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());

        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            // Check whether mid can be answer or not
            int tot_bouq = 0;
            int flower = 0;
            for(int i = 0; i<bloomDay.size() ; i++){
                if(bloomDay[i] <= mid){
                    flower++;
                    if(flower == k){
                        tot_bouq++;
                        flower = 0;
                    }
                }else flower = 0;
            }

            if(tot_bouq < m){
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid -1;
            }
        }

        return ans;

    }
};