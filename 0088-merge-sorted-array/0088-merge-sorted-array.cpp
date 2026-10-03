class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)return ;
        int i = nums1.size()-1 , j = 0;
        while(j < n){
            nums1[i--] = nums2[j++];
        }

        sort(nums1.begin() , nums1.end());
    }
};