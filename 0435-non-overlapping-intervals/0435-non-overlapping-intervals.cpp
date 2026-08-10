class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());

        vector<int> start = intervals.front();

        int ans = 0;

        for(int i=1 ; i< intervals.size() ; i++){
            vector<int> temp = intervals[i];

            if(start[1] > temp[0]){
                ans++;
                start[1] = min(start[1] , temp[1]);
            }else {
                start = temp;
            }
        }

        return ans;
    }
};