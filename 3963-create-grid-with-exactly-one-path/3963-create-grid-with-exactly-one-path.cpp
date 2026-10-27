class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp;
        int i = 0; 
            
        for(int j = 0 ;j < n ; j++){
            temp += '.';
        }
        ans.push_back(temp);
        temp.clear();
        i++;
        for(int j = 0 ;j < n-1 ; j++){
            temp += '#';
        }
        temp += '.';

        while(i++ < m){
            ans.push_back(temp);
        }

        return ans;
    }
};