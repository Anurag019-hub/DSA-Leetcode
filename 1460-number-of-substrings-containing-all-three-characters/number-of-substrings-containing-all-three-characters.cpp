class Solution {
public:
    int numberOfSubstrings(string s) {
        // Track the last seen index of 'a', 'b', and 'c'
        // Initialized to -1 because we haven't seen them yet
        int last_seen[3] = {-1, -1, -1};
        int ans = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Update the last seen position of the current character
            last_seen[s[i] - 'a'] = i;
            
            // If we have seen all three characters at least once
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                // The number of valid substrings ending at i is determined 
                // by the smallest index among the last seen positions.
                int min_idx = min({last_seen[0], last_seen[1], last_seen[2]});
                ans += min_idx + 1;
            }
        }
        
        return ans;
    }
};