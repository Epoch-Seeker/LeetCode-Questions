class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans , temp;

        int i = 0;

        while(i < intervals.size() && intervals[i][0] < newInterval[0])temp.push_back(intervals[i++]);

        temp.push_back(newInterval);
         
        while(i < intervals.size())temp.push_back(intervals[i++]);

        // for(auto t : temp){
        //     cout<<t[0]<<':'<<t[1]<<" ";
        // }

        ans.push_back(temp.front());

        for(int i=1 ; i< temp.size() ; i++){
            vector<int> v = temp[i];

            if(ans.back()[1] < v[0]){
                ans.push_back(v);
            }else {
                ans.back()[1] = max(ans.back()[1] , v[1]);
            }
        }

        return ans;
    }
};