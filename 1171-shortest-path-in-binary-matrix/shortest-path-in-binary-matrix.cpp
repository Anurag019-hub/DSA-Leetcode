class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;
        int m  = grid.size();
        int n =  grid[0].size();
        vector<vector<int>> min_grid(m,vector<int>(n,INT_MAX));
        min_grid[0][0] = 1;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({1,{0,0}});
        vector<pair<int,int>> pos = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
        while(!pq.empty()){
            auto a = pq.front().first;
auto b = pq.front().second.first;
auto c = pq.front().second.second;
            pq.pop();
            if(b==n-1 && c==n-1) return a;
            else{
                for(auto ele : pos){
                    auto [fi,se] = ele;
                    if(b+fi>=0 && b+fi<m && c+se>=0 && c+se<n) if(min_grid[b+fi][c+se]>a+1 && grid[b+fi][c+se]==0){
                        min_grid[b+fi][c+se] = a+1;
                        pq.push({a+1,{b+fi,c+se}});
                    }
                }
            }
        }
        return -1;
    }
};