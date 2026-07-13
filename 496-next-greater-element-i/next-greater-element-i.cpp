class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nextGreaterEle(n,-1);
        stack<int> monotonic_stack;
        monotonic_stack.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!monotonic_stack.empty() && nums2[i]>monotonic_stack.top()){
                monotonic_stack.pop();
            }
            if(monotonic_stack.empty()) nextGreaterEle[i] = -1;
            else  nextGreaterEle[i] = monotonic_stack.top();
            monotonic_stack.push(nums2[i]);
        }
        vector<int> ans;
        for(int ele : nums1){
            for(int i=0;i<n;i++){
                if(nums2[i]==ele) ans.push_back(nextGreaterEle[i]);
            }
        }

        return ans;
    }
};