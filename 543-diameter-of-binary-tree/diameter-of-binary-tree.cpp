/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
  int recursion(TreeNode* root , int& maxi){
     if(root == nullptr) return 0;
        int lrh = recursion(root->left,maxi);
        int rrh = recursion(root->right,maxi);
        maxi  = max(maxi,lrh+rrh);
        return max(lrh,rrh)+1;
  }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int ans=0;
       recursion(root,ans);
       return ans;
    }
};