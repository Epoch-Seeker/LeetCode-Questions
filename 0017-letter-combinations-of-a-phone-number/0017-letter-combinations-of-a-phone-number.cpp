class Solution {
public:
    void solve(string digits , vector<vector<char>>& mp , vector<string>& ans , int idx , string& s){
        if(idx == digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto nbr : mp[digits[idx] - '0']){
            s.push_back(nbr);
            solve(digits , mp , ans , idx+1 , s);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> mp(10);
        int i =0;
        int idx = 2;
        for(char ch = 'a' ; ch <= 'o' ; ch++){
            if(i<3){
                mp[idx].push_back(ch);
                i++;
            }else{
                idx++;
                mp[idx].push_back(ch);
                i=1;
            }
        }

        for(char ch = 'p' ; ch <= 's' ; ch++){
            mp[7].push_back(ch);
        }

        for(char ch = 't' ; ch <= 'v' ; ch++){
            mp[8].push_back(ch);
        }

        for(char ch = 'w' ; ch <= 'z' ; ch++){
            mp[9].push_back(ch);
        }

        vector<string> ans;
        
        idx =0;
        string s = "";
        solve(digits , mp , ans , idx , s);

        return ans;
    }
};