class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        int n = points.size();

        for(int i = 0 ; i< n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                auto x = points[i];
                auto y = points[j];
                int temp = 0;
                if(x[0] - y[0] == 0){
                    for(int k = 0 ; k< n ; k++){
                        auto p = points[k];
                        if(p[0] == x[0])temp++;
                    }
                }
                else{
                    
                    int dx = x[0]-y[0];
                    int dy = x[1]-y[1];
                    
                    for(int k = 0 ; k< n ; k++){
                        int px = points[k][0];
                        int py = points[k][1];

                        if((py - x[1])*dx == dy*(px - x[0]))temp++;
                    }
                }
                ans = max(ans , temp);
            }
        }

        return ans;
    }
};