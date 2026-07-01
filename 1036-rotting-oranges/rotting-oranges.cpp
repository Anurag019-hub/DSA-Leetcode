class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> time(m,vector<int>(n,INT_MAX));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                int val = 0;
                queue<pair<int,int>> q1;
                q1.push({i,j});
                while(!q1.empty()){
                    int ele_same_dept = q1.size();
                    for(int check = 0;check<ele_same_dept;check++){
                        pair<int,int> curr = q1.front();
                    q1.pop();
                    time[curr.first][curr.second] = min(val,time[curr.first][curr.second]);
                    if(curr.first>0 && grid[curr.first-1][curr.second] !=0 && time[curr.first-1][curr.second] > val+1) q1.push({curr.first-1,curr.second});
                    if(curr.first<m-1 && grid[curr.first+1][curr.second] !=0 && time[curr.first+1][curr.second] >val+1 ) q1.push({curr.first+1,curr.second});
                    if(curr.second<n-1 && grid[curr.first][curr.second+1] !=0 && time[curr.first][curr.second+1] >val+1 ) q1.push({curr.first,curr.second+1});
                    if(curr.second>0 && grid[curr.first][curr.second-1] !=0  && time[curr.first][curr.second-1] >val+1 ) q1.push({curr.first,curr.second-1});
                    
                    }
                    val++;

                }
                
            }
        }
      }
      int ans = 0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]== 1 && time[i][j]==INT_MAX){
                return -1;
            }else if(grid[i][j] != 0){
                ans = max(ans,time[i][j]);
            }
        }
      }
      return ans;
    }
};