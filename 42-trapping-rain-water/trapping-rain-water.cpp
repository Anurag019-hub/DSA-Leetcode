class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // approach-1 prefixmin and suffixmin then min of them is subtracted from height[i]
        // vector<int> prefixmin(n);
        // prefixmin[0] = height[0];
        // vector<int> suffixmin(n);
        // suffixmin[n-1] = height[n-1];
        // for(int i=1;i<n;i++){
        //     prefixmin[i] = max(prefixmin[i-1],height[i]);
        //     suffixmin[n-1-i] = max(suffixmin[n-i],height[n-1-i]);
        // }
        // long long ans=0; 
        // for(int i=0;i<n;i++){
        //     int aa = min(prefixmin[i],suffixmin[i]) - height[i];
        //     ans+= (aa>0?aa:0);
        // }
        // return (int)ans;

        //approach -2 we are only looking for min from either side so no need for complete
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // Left side is smaller, so left_max dictates the bottleneck
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    ans += left_max - height[left];
                }
                left++;
            } else {
                // Right side is smaller or equal, so right_max dictates the bottleneck
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    ans += right_max - height[right];
                }
                right--;
            }
        }
        
        return ans;
    }
};