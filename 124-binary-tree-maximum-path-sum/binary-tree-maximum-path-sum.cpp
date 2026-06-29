class Solution {
private:
    int calculateMaxPath(TreeNode* root, int& maxi) {
        if (root == nullptr) return 0;

        // 1. Calculate the max path sum from left and right subtrees.
        // If they return a negative sum, we ignore them by taking max(0, ...).
        int leftMax = max(0, calculateMaxPath(root->left, maxi));
        int rightMax = max(0, calculateMaxPath(root->right, maxi));

        // 2. Update our global maximum by considering the path that 
        // turns/connects through the current root node.
        maxi = max(maxi, root->val + leftMax + rightMax);

        // 3. Return the maximum single-branch path sum to the parent node.
        return root->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        calculateMaxPath(root, maxi);
        return maxi;
    }
};