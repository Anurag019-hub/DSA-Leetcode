class Solution {
public:
    bool dfs(vector<vector<int>>& grid ,vector<vector<bool>> &visited,int r,int c,int i,int j){
        if(i<0||i>=r||j<0||j>=c) return false;
        if(visited[i][j] || grid[i][j]==1) return true;
        visited[i][j] =true;
     bool d1 = dfs(grid, visited, r, c, i + 1, j);
bool d2 = dfs(grid, visited, r, c, i, j + 1);
bool d3 = dfs(grid, visited, r, c, i - 1, j);
bool d4 = dfs(grid, visited, r, c, i, j - 1);

return d1 && d2 && d3 && d4;
       
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c  = grid[0].size();
        int ans = 0; 
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    bool is_good = dfs(grid,visited,r,c,i,j);
                    if(is_good) ans++;
                }
            }
        }
        return ans;
    }
};