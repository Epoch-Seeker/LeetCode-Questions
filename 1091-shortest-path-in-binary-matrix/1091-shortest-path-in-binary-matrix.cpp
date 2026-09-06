class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;

        queue<vector<int>> q;
        q.push({0 , 0 , 1});
        // vector<vector<int>> vis(n , vector<int>(n , 0));
        grid[0][0] = 1;

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t[0];
            int j = t[1];
            int ans = t[2];

            if(i == n-1 && j == n-1)return ans;

            for(int k = 0 ; k<8 ; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x <0 || x >=n || y <0 || y >= n)continue;

                if(!grid[x][y]){
                    grid[x][y] = 1;
                    q.push({x , y , ans +1});
                }
            }
        }
        return -1;
    }
};