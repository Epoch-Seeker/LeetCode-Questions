class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0)return {newInterval};
        vector<vector<int>> ans;

        for(int i = 0 ; i< intervals.size() ; i++){
            if(intervals[i][0] > newInterval[0]){
                intervals.insert(intervals.begin()+i , newInterval);
                newInterval.clear();
                break;
            }
        }

        if(!newInterval.empty())intervals.push_back(newInterval);

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