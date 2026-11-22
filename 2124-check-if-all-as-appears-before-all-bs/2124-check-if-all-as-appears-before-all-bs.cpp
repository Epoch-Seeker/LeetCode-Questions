class Solution {
public:
    bool checkString(string s) {
        bool b = false;

        for(char ch : s){
            if(ch == 'a'){
                if(b)return false;
            }else b = true;
        }

        return true;
    }
};