class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int sum = 1;

        int i= 1;

        while(i < s.size()){
            if(s[i] == '(')sum++;
            else sum--;
            if(sum == 0){
                sum = 1;
                i+=2;
                continue;
            }
            ans.push_back(s[i++]);
        }

        return ans;
    }
};