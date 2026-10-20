class Solution {
public:
    int maxDepth(string s) {
        
        int ans = 0;
        int temp = 0;

        for(char ch : s){
            if(ch == '('){
                temp++;
            }else if(ch == ')')temp--;

            ans = max(ans , temp);
        }
 

        return ans;
    }
};