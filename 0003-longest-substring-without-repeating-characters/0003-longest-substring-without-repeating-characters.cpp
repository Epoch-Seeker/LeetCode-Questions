class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        vector<int> lastidx(127 , -1);

        int i = 0;

        for(int j = 0;j<s.size();j++){
            i = max(i , lastidx[s[j]]+1);

            ans = max(ans , j-i+1);

            lastidx[s[j]] = j;
        }
        

        return ans;
    }
};