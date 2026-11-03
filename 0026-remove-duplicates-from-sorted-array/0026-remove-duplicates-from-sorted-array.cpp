class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for(int i : nums)st.insert(i);

        int i = 0;
        auto it = st.begin();

        while(it != st.end()){
            nums[i++] = *it;
            it++;
        }

        return st.size();
    }
};