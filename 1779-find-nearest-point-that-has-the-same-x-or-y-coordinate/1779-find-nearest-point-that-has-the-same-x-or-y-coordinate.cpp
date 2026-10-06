class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int idx = -1;

        int i=0 , n = points.size();

        int dis = INT_MAX;

        while(i < n){
            auto p = points[i++];
            if(p[0] != x && p[1] != y)continue;

            int temp = abs(x - p[0]) + abs(y - p[1]);

            if(temp < dis){
                idx = i-1;
                dis = temp;
            }
        }

        return idx;
    }
};