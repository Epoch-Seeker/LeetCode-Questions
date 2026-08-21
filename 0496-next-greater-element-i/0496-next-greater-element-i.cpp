class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;

        st.push(-1);

        int n = nums2.size();

        vector<int> ans(n , 0);

        for(int i = n-1 ; i>= 0 ; i--){
            while(st.top() != -1 && st.top() < nums2[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {

            int t = nums1[i];

            for (int j = 0; j < n; j++) {

                if (nums2[j] == t) {
                    nums1[i] = ans[j];   // <-- FIX
                    break;
                }
            }
        }

        return nums1;

    }
};