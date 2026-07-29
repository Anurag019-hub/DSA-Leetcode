class Solution {
public:
    int dfs(int i,int j,int m, int n ,vector<vector<bool>> &visited,vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int ans = 0;
        if(visited[i][j]==true) return dp[i][j];
        visited[i][j] = true;
        if(i>0 && matrix[i-1][j]>matrix[i][j] ) ans = max(ans, dfs(i-1,j,m,n,visited,matrix,dp));
        if(i<m-1 && matrix[i+1][j]>matrix[i][j]) ans = max(ans, dfs(i+1,j,m,n,visited,matrix,dp));
        if(j>0 && matrix[i][j-1]>matrix[i][j]) ans = max(ans, dfs(i,j-1,m,n,visited,matrix,dp));
        if(j<n-1 && matrix[i][j+1]>matrix[i][j]) ans = max(ans, dfs(i,j+1,m,n,visited,matrix,dp));
        return dp[i][j] = 1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    ans = max(ans , dfs(i,j,m,n,visited,matrix,dp));
                }
            }
        }
        return ans;
    }
};