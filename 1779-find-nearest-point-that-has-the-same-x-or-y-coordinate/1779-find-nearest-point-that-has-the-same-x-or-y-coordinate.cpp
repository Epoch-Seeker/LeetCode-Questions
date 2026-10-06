class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int idx = -1;

        int i=0 , n = points.size();

        int dis = INT_MAX;

        while(i < n){
             
            if(points[i][0] == x || points[i][1] == y){
                int temp = abs(x - points[i][0]) + abs(y - points[i][1]);

                if(temp < dis){
                    idx = i;
                    dis = temp;
                }
            } 
            i++;
        }

        return idx;
    }
};