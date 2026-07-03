class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int mx = INT_MIN;
        for(auto i : piles){
            if(i > mx)mx = i;
        }

        int ans = INT_MAX;

        int l = 1;
        int r = mx;

        while(l <= r ){
            int m = l + (r- l)/2;

            long long  tot_hr = 0;

            for(auto i : piles){
                tot_hr += (i/m);
                if(i % m != 0){
                    tot_hr++;
                }
            }

            if(tot_hr <= h) {
                ans = m;
                r = m -1;
            }

            else l = m+1;
        }

        return ans ;
    }
};