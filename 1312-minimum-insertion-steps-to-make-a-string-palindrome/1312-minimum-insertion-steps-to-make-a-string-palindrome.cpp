class Solution {
public:
    int solve(string& s ){
        int n = s.size();
        vector<int> cur(n+1 , 0);
        vector<int> down(n+1 , 0);

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+1 ; j < n ; j++){
                if(s[i] == s[j]){
                    cur[j] = down[j-1];
                }

                else cur[j] = 1 + min(down[j], cur[j-1]);
            }
            down = cur;
        }

        return down[n-1];
        
    }
    int minInsertions(string s) {
        return solve(s);
    }
};