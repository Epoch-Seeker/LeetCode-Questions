class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin() , intervals.end());

        ans.push_back(intervals.front());

        for(int i=1 ; i< intervals.size() ; i++){
            vector<int> v = intervals[i];

            if(ans.back()[1] < v[0]){
                ans.push_back(v);
            }else {
                ans.back()[1] = max(ans.back()[1] , v[1]);
            }
        }

        return ans;
    }
};