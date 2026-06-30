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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> a;
        queue<TreeNode*> store;
        if(root==nullptr) return {};
        store.push(root);
        while(!store.empty()){
            vector<int> val;
            int n  = store.size();
            for(int i=0;i<n;i++){
                TreeNode* curr= store.front();
                val.push_back(curr->val);
                store.pop();
                if(curr->left!=nullptr) store.push(curr->left);
                if(curr->right!=nullptr) store.push(curr->right);
            }
            a.push_back(val);
        }
        vector<int> ans;
        for(auto ele:a){
            int z = ele.size();
            if(z>0) ans.push_back(ele[z-1]);
        }
        return ans;
    }
};