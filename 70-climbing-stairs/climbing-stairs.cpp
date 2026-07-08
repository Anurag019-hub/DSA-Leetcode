class Solution {
public:
    int climbStairs(int n) {
     int prev_curr = 1;
     int curr =1;
     for(int i=2;i<=n;i++){
        int temp_curr = prev_curr+curr;
        prev_curr= curr;
        curr=temp_curr;
     }
     return curr;
    }
};