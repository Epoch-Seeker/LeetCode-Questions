class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int , int>> q;

        for(int i=0;i< m ; i++){
            for(int j = 0 ;j< n ; j++){
                if(mat[i][j] == 0){
                     
                    q.push({i , j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }

        int dx[] = {-1 , 1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int i = t.first;
            int j = t.second;

            for(int k = 0 ;k <4 ; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x <0 || x >= m || y < 0 || y >= n)continue;

                if(mat[x][y] != -1)continue;

                mat[x][y] = mat[i][j] + 1;

                q.push({x , y});
            }
        }

        return mat;
    }
};