class Solution {
public:
    int solve(vector<int>& cost , int i , int& ans){
        if(i >= cost.size())return 0;

        int left = solve(cost , 2*i + 1 , ans);
        int right = solve(cost , 2*i + 2 , ans);

        ans += abs(left - right);

        return cost[i] + max(left , right);
        
    }
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        solve(cost , 0 , ans );
        return ans;
    }
};