class Solution {
public:
    int minInsertions(string s) {
        for(int i=0; i< s.size() ; i++){
            if(s[i] == ')'){
                if(i-1>=0 && s[i-1] == s[i]){
                    s[i-1] = '1';
                    s[i] = '0';
                }
                 
            } 
        }

        int ans = 0;

        for(int i =0; i< s.size() ; i++){
            if(s[i] == ')'){
                ans++;
                s[i] = '1';
            }
        }

        int sum = 0;

        for(char ch : s){
            if(ch == '(')sum++;
            else {
                if(ch == '1')sum--;
            }

            if(sum < 0){
                ans++;
                sum = 0;
            }
        }

        while(sum--)ans+=2;
        
        return ans;
    }
};