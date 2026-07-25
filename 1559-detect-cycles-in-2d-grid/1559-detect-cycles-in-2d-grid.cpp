class Solution {
public:

    vector<pair<int,int>> dirn = {{-1,0},{1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j,int pi,int pj){
        visited[i][j] = 1;

        for(auto [x,y] : dirn){
            int dx = x + i;
            int dy = y + j;
            if(dx >= 0 && dy >=0 && dx < grid.size() && dy < grid[0].size()){
                if(visited[dx][dy] == 0 && grid[dx][dy] == grid[i][j]){
                    if(dfs(grid,visited,dx,dy,i,j)) return true;;
                }else if(visited[dx][dy] == 1 && grid[dx][dy] == grid[i][j]){
                    if(dx != pi || dy != pj){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));


       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                if(dfs(grid,visited,i,j,-1,-1)) return true;
            }
        }
       }

       return false;
    }
};