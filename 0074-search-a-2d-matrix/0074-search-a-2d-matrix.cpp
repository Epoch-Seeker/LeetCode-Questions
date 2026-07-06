class Solution {
public:
    int get_row(vector<vector<int>>& matrix, int target){
        int l = 0;
        int h = matrix.size() - 1;
        int end = matrix[0].size()-1;

        while(l <= h){

            int m = l + (h - l)/2;

            if(matrix[m][0] <= target && matrix[m][end] >= target)return m;

            if(matrix[m][0] > target) h = m -1;

            else l = m + 1;
        }

        return -1;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = get_row(matrix , target);

        if(row == -1)return false;

        int l = 0;
        int h = matrix[row].size()-1;

        while(l <= h){

            int m = l + (h - l)/2;

            if(matrix[row][m] == target)return true;

            if(matrix[row][m] > target)h = m - 1;

            else l = m + 1;
        }

        return false;
    }
};