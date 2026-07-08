class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<vector<int>> copygraph(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto ele: graph[i]){
                    copygraph[ele].push_back(i);
            }
        }

        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            indegree[i] = graph[i].size();
            if(indegree[i]==0){
                q.push(i);
                visited[i] = true;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(q.front());
            q.pop();
            for(auto ele : copygraph[curr]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        if(ans.size()>0)sort(ans.begin(),ans.end());
        return ans;
    }
};