class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode* leftPtr = root;
        TreeNode* rightPtr = root;
        
        // Find the height of the leftmost path
        while (leftPtr) {
            leftHeight++;
            leftPtr = leftPtr->left;
        }
        
        // Find the height of the rightmost path
        while (rightPtr) {
            rightHeight++;
            rightPtr = rightPtr->right;
        }
        
        // If heights match, it's a perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }
        
        // Otherwise, count root + recurse on subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};