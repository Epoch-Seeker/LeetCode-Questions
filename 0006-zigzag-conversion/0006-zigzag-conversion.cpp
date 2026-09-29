class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        vector<string> v(numRows);

        int i = 0;
        bool plus = true;
        
        for(char ch : s){
            v[i].push_back(ch);
            if(i == 0)plus = true;
            if(i == numRows-1)plus = false;
            if(plus)i++;
            else i--;
        }

        string ans;

        for(auto  s : v){
            ans += s;
        }

        return ans;
    }
};