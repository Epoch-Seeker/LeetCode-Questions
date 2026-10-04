class Solution {
public:
    bool checkValidString(string s) {
        int low = 0 , high = 0;
        int i = 0 , n = s.size();
         
        while(i < n){
            if(s[i] == '('){
                low++;
                high++;
            }
            else if(s[i] == ')'){
                low--;
                high--;
            }
            else {
                low--;// * as )
                high++;// * as (
            }

            if(high < 0 )return false;

            low = max(low , 0);
            i++;
        }

        return low == 0;
    }
};