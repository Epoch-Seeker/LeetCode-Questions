class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> st;
        int a , b;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(st.count(comp)){
                a = comp;
                b = nums[i];
                break;
            }
            st.insert(nums[i]);
        }

        int p = -1 , q = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == a && p == -1)p=i;
            else if(nums[i] == b && q == -1)q = i;
        }

        return {p,q};
    }
};