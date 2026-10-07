class Solution {
public:
    unordered_map<string , bool> mp;
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
                if(!mp[s]){
                    ans.push_back(s);
                    mp[s] = true;
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            solve(s , ans , i+1 , remove);
            return;
        }

        if(s.size() - i == remove){
            char ch = s[i];
            s.erase(i,1);
            solve(s , ans , i , remove-1);
            s.insert(i , 1 , ch);
        }else{
            // not erase
            solve(s , ans , i+1 , remove);
            // erase
            char ch = s[i];
            s.erase(i,1);
            solve(s , ans , i , remove-1);
            s.insert(i , 1 , ch);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        for(int remove = 0; remove <=n ; remove++){
            mp.clear();
            vector<string> ans;
            solve(s , ans , 0 , remove);
            if(ans.size()>0)return ans;
        }
        return {""};
    }
};