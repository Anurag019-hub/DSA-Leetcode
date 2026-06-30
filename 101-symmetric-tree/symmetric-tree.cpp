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
    bool is_mirror(TreeNode* first , TreeNode* second){
        if(first==nullptr && second==nullptr) return true;
        else if(first!=nullptr && second!=nullptr && first->val==second->val){
            return is_mirror(first->left,second->right)&& is_mirror(first->right,second->left);
        }else return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return is_mirror(root->left,root->right);
    }
};