class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        
        // Build adjacency list: course -> dependent courses
        for (auto& ele : prerequisites) {
            edges[ele[1]].push_back(ele[0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto ele : edges[i]){
                indegree[ele]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neighbor:edges[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        return ans.size()==numCourses;
    }
};