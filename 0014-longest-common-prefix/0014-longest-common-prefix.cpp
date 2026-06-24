class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        if(strs.size() == 1)return strs[0];
        bool all_zero = true;
        for(auto a : strs){
            if(a.size() > 0)all_zero = false;
        }

        if(all_zero)return "";

        for(int i = 0 ; i< strs[0].size() ; i++){
            char ch = strs[0][i];
            bool he = true;
            for(int j = 1 ; j< strs.size() ; j++){
                if(strs[j][i] != ch){
                    he = false;break;
                }
            }
            if(he) res += ch;
            else break;
        }

        return res;
    }
};