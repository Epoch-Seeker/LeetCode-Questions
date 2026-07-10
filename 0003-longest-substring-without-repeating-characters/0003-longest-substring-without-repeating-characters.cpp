class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();
        int ans = 0;
        vector<bool> vis(127 , false);

        int i = 0;
        int j = 0;

        while(j < s.size()){

            while(vis[s[j]]){
                vis[s[i]] = false;
                i++;
            }

            vis[s[j]] = true;
            ans = max(ans , j-i+1);
            j++;
        }
        

        return ans;
    }
};