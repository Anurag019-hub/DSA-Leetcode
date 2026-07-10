class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adjlist;
        int p = flights.size();
        for(int i=0;i<p;i++){
            adjlist[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int nodes = adjlist.size();
        vector<int>cost(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,src});
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int steps = curr[0];
            int curr_cost = curr[1];
            int curr_node= curr[2];
            for(auto ele : adjlist[curr_node]){
                if(steps<=k && curr_cost+ele.second<cost[ele.first]){
                    cost[ele.first]=curr_cost+ele.second;
                    pq.push({steps+1,cost[ele.first],ele.first});
                }
            }
        }

        return cost[dst]==INT_MAX?-1:cost[dst];
    }
};