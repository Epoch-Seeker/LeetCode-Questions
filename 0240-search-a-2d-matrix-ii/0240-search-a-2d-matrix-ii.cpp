class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(auto &row : matrix){
            int low = 0;
            int high = matrix[0].size()-1;
            
            while(low <= high){

                int mid = low + (high - low)/2;

                if(row[mid] == target)return true;

                if(row[mid] > target) high = mid - 1;

                else low = mid + 1;
            }
        }

        return false;
    }
};