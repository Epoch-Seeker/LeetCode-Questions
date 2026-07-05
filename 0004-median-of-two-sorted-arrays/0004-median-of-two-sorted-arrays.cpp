class Solution {
public:
    double solve(vector<int>& nums1, vector<int>& nums2){
        int  n = nums1.size();
        int  m = nums2.size();
        int low = 0;
        int high = n;
        
        
        while(low <= high){
            
            int mid1 = low + (high - low)/2;
            
            int mid2 = ((n + m + 1)/2 - mid1);
            
            int l1 = INT_MIN;
            
            if(mid1 - 1 >= 0){
                l1 = nums1[mid1 - 1];
            }
            
            int l2 = INT_MIN;
            
            if(mid2 - 1 >=0){
                l2 = nums2[mid2 - 1];
            }
            
            int r1 = INT_MAX , r2 = INT_MAX;
            
            if(mid1 < n)r1 = nums1[mid1];
            
            if(mid2 < m)r2 = nums2[mid2];
            
            if(l1 > r2){
                high = mid1 - 1;
            }
            
            else if(l2 > r1){
                low = mid1 + 1;
            }
            
            else {
                if((n+m)%2 == 0){
                    return (max(l1 , l2) + min(r1 , r2))/2.0;
                }else return max(l1 , l2);
            }
            
            
        }

        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())return solve(nums2 , nums1);
        return solve(nums1 , nums2);
        
        // return 0;
    }
};