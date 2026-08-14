class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node , vector<int>& col , int c){

        col[node] = c;

        for(auto nbr : graph[node]){
            if(col[nbr] == 0){
                if(dfs(graph , nbr , col , c == 1? 2 : 1))return true;
            }else {
                if(col[nbr] == c)return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(), 0);

        for(int i=0;i< graph.size() ; i++){
            if(col[i] == 0){
                if(dfs(graph , i , col , 1))return false;
            }
        }
         
        return true;
    }
};