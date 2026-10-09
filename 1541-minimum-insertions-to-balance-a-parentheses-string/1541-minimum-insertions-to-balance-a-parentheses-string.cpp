class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int sum = 0;
        for(int i=0; i< s.size() ; i++){

            if(s[i] == ')'){
                if(i+1 < s.size() && s[i+1] == s[i]){
                    sum--;
                    i++;
                }else{
                    ans++;
                    sum--;
                }
                 
            }else sum++;

            if(sum < 0){
                ans++;
                sum = 0;
            }
        }

        while(sum--)ans+=2;
        
        return ans;
    }
};