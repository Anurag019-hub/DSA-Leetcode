class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap to store the fuel capacity of the stations we have passed
        priority_queue<int> max_fuel;
        
        int currentFuel = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();
        
        // Loop until our current reachable distance is less than the target
        while (currentFuel < target) {
            // Add all stations we can reach with our current fuel to the max-heap
            while (i < n && stations[i][0] <= currentFuel) {
                max_fuel.push(stations[i][1]);
                i++;
            }
            
            // If we can't move further and have no past stations to refuel from
            if (max_fuel.empty()) {
                return -1;
            }
            
            // Take the max fuel available from past passed stations
            currentFuel += max_fuel.top();
            max_fuel.pop();
            stops++;
        }
        
        return stops;
    }
};