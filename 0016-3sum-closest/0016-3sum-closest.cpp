class Solution {
public:
    int twosum(vector<int>& nums, int tar , int i) {
        int diff = INT_MAX;
        int ans ;
        set<int> st;
        for(i ; i< nums.size(); i++){
            int t = nums[i];
            int comp = tar -t;
            auto it = st.lower_bound(comp);
            // Candidate >= comp
            if (it != st.end()) {
                if (diff > abs(comp - *it)){
                    diff = abs(comp - *it);
                    ans = t + *it;
                }
                    
            }

            // Candidate < comp
            if (it != st.begin()) {
                --it;
                if (diff > abs(comp - *it)){
                    diff = abs(comp - *it);
                    ans = t + *it;
                }
                   
            }
            // cout<<ans<<endl;
            st.insert(nums[i]);
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans ;
        int n= nums.size();
        for(int i = 0 ;i< n ; i++){
            int temp = target - nums[i];
            int k = twosum(nums , temp , i+1);
            cout<<k<<endl;
            if(k != INT_MAX && diff > abs((nums[i] + k - target))){
                diff = abs((nums[i] + k - target));
                ans = nums[i] + k;
            }
        }
        return ans;
    }
};