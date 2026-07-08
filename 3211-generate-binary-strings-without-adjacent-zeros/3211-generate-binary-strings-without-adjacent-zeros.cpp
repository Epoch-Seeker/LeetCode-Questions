class Solution {
public:
    void solve(int n , bool can , vector<string>& ans , string& s){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        if(can){
            // allowed to take 0
            s.push_back('0');
            solve(n, false , ans , s);
            s.pop_back();
             
        }

        s.push_back('1');
        solve(n, true , ans , s);
        s.pop_back();
            

        
    }
    vector<string> validStrings(int n) {
        bool can = true;
        vector<string>ans;
        string s ;
        solve(n , can , ans , s);
        return ans;
    }
};