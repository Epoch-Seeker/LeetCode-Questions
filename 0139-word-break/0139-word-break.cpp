class Solution {
public:
    bool solve(string s ,vector<string>& wordDict , int start , vector<int>& dp ){
        
        if(start == s.size()){
            return true;
        }

        if(dp[start] != -1)return dp[start];

        for(int end = start ; end < s.size() ; end++){
            string temp = s.substr(start , end - start +1);
            auto itr = find(wordDict.begin() , wordDict.end() ,  temp);
            if(itr != wordDict.end()){
                if(solve(s , wordDict , end+1 , dp))return dp[start]  = true;
            }
        }

        return dp[start]  = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n , -1);
        return solve(s , wordDict , 0 , dp);

    }
};