class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0,j=0;

        double m1 = -1, m2 = -1;

        for(int t=0;t <= (n+m)/2 ; t++){
            m2 = m1;
            if(i < n && j < m){
                if(nums1[i] < nums2[j]){
                    m1 = nums1[i++];
                }else m1 = nums2[j++];
            }

            else if(i < n){
                m1 = nums1[i++];
            }

            else if(j < m){
                m1 = nums2[j++];
            }
        }

        if((n+m)%2 ==0){
            return (m1 + m2)/2.0;
        }else return m1;
    }
};