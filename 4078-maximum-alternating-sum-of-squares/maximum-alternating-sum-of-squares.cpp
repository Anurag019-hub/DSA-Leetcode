class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int op ;
        if(n%2==0)op = n/2;
        else op = n/2+1;
        long long ans = 0;
        for(int i=0;i<op;i++){
            ans += (nums[i]*nums[i]);
        }
        for(int i=op;i<n;i++){
            ans -= (nums[i]*nums[i]);
        }
        return ans;
    }
};