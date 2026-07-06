class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count =0,row=0;
        int n = mat.size(),m= mat[0].size();

        for(int i=0 ;i<n ; i++){
            int temp=0;
            for(int j=0 ;j<m ;j++){
                if(mat[i][j]==1){
                    temp++;
                }
            }
            if(temp>count){
                count = temp;
                row=i;
            }
        }
        return {row, count};
    }
};