class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
       //aprroach-1 get all the two sums and compare - t.c -> O(n^2) and sc- >O(1); 
    //    for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]+nums[j]==target) return{i,j};
    //     }
    //    }
    //    return{};

    // aprroach-2 get set and see if we the elem we need is present
      unordered_map<int,int> store;
      for(int i=0;i<n;i++){
         store[nums[i]] = i;
      }

      for(int i=0;i<n;i++){
        if(store.find(target -nums[i])!= store.end() && store[target - nums[i]]!=i){
            return{i,store[target - nums[i]]};
        }
      }
      return{};
    }
};