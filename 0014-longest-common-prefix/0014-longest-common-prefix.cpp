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

        int idx =0;
        
        while(true){
            bool same = true;
            char ch;
            for(int i= 0; i<strs.size()-1 ; i++){
                 
                if(idx < strs[i].size() && idx < strs[i+1].size()){
                    if(strs[i][idx] != strs[i+1][idx])same = false;
                    else ch = strs[i][idx];
                }else same = false;
                if(!same){
                    return res;
                }
                
            }
            res += ch;
            idx++;
        }
        return "0";
    }
};