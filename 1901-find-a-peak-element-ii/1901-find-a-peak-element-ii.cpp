class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int l = 0;
        int h = mat[0].size()-1;

        while(l <= h){

            int m = l + (h - l)/2;

            int maxidx = -1;
            int temp = INT_MIN;
            for(int i=0;i<mat.size();i++){
                if(mat[i][m] > temp){
                    maxidx = i;
                    temp = mat[i][m];
                }
            }

            // left element
            int left = (m == 0? -1 : mat[maxidx][m-1]);

            // right element
            int right = (m == mat[0].size()-1? -1 : mat[maxidx][m+1]);

            // check
            if(mat[maxidx][m] > left && mat[maxidx][m] > right){
                return {maxidx , m};
            } 

            if(mat[maxidx][m] < left) h = m -1;

            else l = m +1;  
            
        }
        

        return {};
    }
};