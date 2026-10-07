class Solution {
public:
    // unordered_map<string , bool> mp;
    void solve(string& s , vector<string>& ans , int i , int remove){
        if(i == s.size()){
            if(remove != 0)return;
        }
        if(remove == 0){
            int temp = 0;
            for(char ch : s){
                if(ch == '(')temp++;
                else if(ch == ')') temp--;
                
                if(temp < 0)return;
            }
            if(temp == 0){
                // if(!mp[s]){
                    ans.push_back(s);
                    // mp[s] = true;
                // }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            solve(s , ans , i+1 , remove);
            return;
        }

        // not erase
        solve(s , ans , i+1 , remove);
        // erase
        if(i == 0 || s[i] != s[i-1]){

            char ch = s[i];

            s.erase(i, 1);

            solve(s, ans, i, remove - 1);

            s.insert(i, 1, ch);
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int temp = 0;
        int remove = 0;
        for(char ch : s){
            if(ch == '(')temp++;
            else if(ch == ')') temp--;
            
            if(temp < 0){
                remove++;
                temp++;
            }
        }

        while(temp--)remove++;

        if(remove == 0)return {s};
         
        vector<string> ans;
        solve(s , ans , 0 , remove);
        return ans;
    }
};