class Solution {
public:
    void solve(vector<int>& g, vector<int>& s , int& ans , int i , int j){
        if(i == g.size() || j == s.size())return;

        if(g[i] > s[j]){
            solve(g , s , ans , i , j+1);
        }
        else {
            ans++;
            solve(g , s , ans , i+1 , j+1);
        }
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        solve(g , s , ans , 0 , 0);

        return ans;
    }
};