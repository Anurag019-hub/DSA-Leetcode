class Solution {
public:
    bool pos(int target,int idx,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0) return true;
        else if(target<0) return false;
        else if(idx==nums.size()) return false;
        if(dp[target][idx]!=-1) return dp[target][idx]>0;
        dp[target][idx] = (pos(target,idx+1,nums,dp)||pos(target-nums[idx],idx+1,nums,dp))?1:0;
        return dp[target][idx]>0;

    }
    bool canPartition(vector<int>& nums) {
        long long total = accumulate(nums.begin(),nums.end(),0ll);
        if(total%2!=0) return false;
        else {
            vector<vector<int>>dp(total/2+1,vector<int>(nums.size(),-1));
           return pos(total/2,0,nums,dp);
        }
    }
};