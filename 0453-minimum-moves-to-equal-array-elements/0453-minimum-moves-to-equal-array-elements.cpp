class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;

        for(int i : nums){
            mn = min(mn , i);
        }

        int ans = 0;

        for(int i : nums){
            ans += abs(i - mn);
        }

        return ans;
    }
};