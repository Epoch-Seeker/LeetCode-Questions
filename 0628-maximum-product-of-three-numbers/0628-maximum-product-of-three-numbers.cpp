class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long max1 = INT_MIN;
        long long max2 = INT_MIN;
        long long max3 = INT_MIN;

        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for(auto i: nums){
            if(i > max1){
                max3 = max2;
                max2 = max1;
                max1 = i;
            }else if(i > max2){
                max3 = max2;
                max2 = i;
            }else if(i > max3)max3 = i;

            if(i < min1){
                min2 = min1;
                min1 = i;
            }else if(i < min2)min2 = i;
        }

        // cout<<max1<<" " << max2 <<" "<< max3 <<" "<<min1<<" "<<min2;

        long long p1 = max1*max2*max3;
        long long p2 = max1*min1*min2;

        if( p1 > p2)return p1 ;
        return p2;

    }
};