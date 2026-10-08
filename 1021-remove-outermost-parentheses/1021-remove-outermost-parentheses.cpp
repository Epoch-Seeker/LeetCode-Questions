class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int sum = 0;
        int i=0;
        while(i < s.size()){
            if(sum == 0){
                if(s[i] == '(')sum++;
                else sum--;
            }else{
                if(s[i] == '(')sum++;
                else sum--;
                if(sum != 0 )
                    ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};