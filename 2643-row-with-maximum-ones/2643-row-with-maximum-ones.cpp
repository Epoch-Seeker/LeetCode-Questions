class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int sum = 0;
        int idx = 0;
        int j = 0;

        for(auto i : mat){
            int temp = accumulate(i.begin() , i.end() , 0);
            if(temp > sum){
                sum = temp;
                idx = j;
            }
            j++;
        }

        return {idx , sum};
    }
};