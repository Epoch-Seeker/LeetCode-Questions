class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));

        queue<vector<int>> q;

        for(int i=0;i< m ; i++){
            for(int j = 0 ;j< n ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = true;
                    q.push({i , j , 0});
                }
            }
        }

        int dx[] = {-1 , 1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int i = t[0];
            int j = t[1];
            int dis = t[2];

            if(mat[i][j] == 1)mat[i][j] = dis;

            for(int k = 0 ;k <4 ; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x <0 || x >= m || y < 0 || y >= n || vis[x][y])continue;

                vis[x][y] = true;
                q.push({x , y , dis + 1});
            }
        }

        return mat;
    }
};