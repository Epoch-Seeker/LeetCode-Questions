class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        for(char ch : s){

            if(ch != ' '){
                temp.push_back(ch);
            }

            else {
                if(temp.empty())continue;
                reverse(temp.begin() , temp.end());
                if(!ans.empty())ans += ' ';
                ans += temp;
                temp.clear();
            }
                
        }
        if(!temp.empty()){
            reverse(temp.begin() , temp.end());
            if(!ans.empty())ans += ' ';
            ans += temp;
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};