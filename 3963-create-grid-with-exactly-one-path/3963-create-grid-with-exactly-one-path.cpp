class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string one , sec;
        int i = 1; 
            
        for(int j = 0 ;j < n ; j++){
            one += '.';
            sec += '#';
        }
        ans.push_back(one);
        
        sec.back() = '.';

        while(i++ < m){
            ans.push_back(sec);
        }

        return ans;
    }
};