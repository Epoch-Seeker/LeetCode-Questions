class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int tar = image[sr][sc];
        if(tar == color) return image;

        queue<vector<int>> q;

        int m = image.size();
        int n = image[0].size();

        q.push({sr , sc});

        vector<pair<int , int>> dr = {{0, -1} , {0, 1} , {1 , 0} , {-1 , 0}};

        while(!q.empty()){
             
            auto v = q.front();
            q.pop();

            int i= v[0];
            int j= v[1];

            image[i][j] = color;

            for(auto d : dr){
                int x = i + d.first;
                int y = j + d.second;

                if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == tar){
                    q.push({x , y});
                }
            }  

        }

        return image;
    }
};