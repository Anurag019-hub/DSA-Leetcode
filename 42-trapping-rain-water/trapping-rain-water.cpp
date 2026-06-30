class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // approach-1 prefixmin and suffixmin then min of them is subtracted from height[i]
        vector<int> prefixmin(n);
        prefixmin[0] = height[0];
        vector<int> suffixmin(n);
        suffixmin[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            prefixmin[i] = max(prefixmin[i-1],height[i]);
            suffixmin[n-1-i] = max(suffixmin[n-i],height[n-1-i]);
        }
        long long ans=0; 
        for(int i=0;i<n;i++){
            int aa = min(prefixmin[i],suffixmin[i]) - height[i];
            ans+= (aa>0?aa:0);
        }
        return (int)ans;
    }
};