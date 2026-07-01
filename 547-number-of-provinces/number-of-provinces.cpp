class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        queue<int> q1;
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
          if(visited[i]!=1){
            ans++;
            visited[i]=1;
            q1.push(i);
            while(!q1.empty()){
                int curr_node= q1.front();
                q1.pop();
                for(int j=0;j<n;j++){
                    if(isConnected[curr_node][j]==1 && visited[j]==0){
                        q1.push(j);
                        visited[j]=1;
                    }
                }
            }
          }
        }
        return ans;


    }
};