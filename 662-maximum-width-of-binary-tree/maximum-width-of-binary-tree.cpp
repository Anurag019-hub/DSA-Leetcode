class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        // Using unsigned long long to safely handle large indices before subtraction
        queue<pair<TreeNode*, unsigned long long>> q; 
        q.push({root, 0});
        unsigned long long max_width = 0;
        
        while (!q.empty()) {
            int n = q.size();
            unsigned long long start_idx = q.front().second; // First node's index at this level
            unsigned long long le = 0, me = 0;
            
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                // Normalize index by subtracting start_idx to prevent overflow
                unsigned long long curr_num = q.front().second - start_idx; 
                q.pop();
                
                if (i == 0) le = curr_num;
                if (i == n - 1) me = curr_num;
                
                if (curr->left) q.push({curr->left, 2 * curr_num});
                if (curr->right) q.push({curr->right, 2 * curr_num + 1});
            }
            max_width = max(max_width, me - le + 1);
        }
        return max_width;
    }
};