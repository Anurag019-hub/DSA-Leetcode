class Solution {
private:
    // Added the missing '>' to close the outer map
    void recursion(TreeNode* root, map<int, map<int, vector<int>>> &ans, int row, int col) {
        if (root == nullptr) return;
        
        // Removed the extra dot '.' between brackets
        ans[col][row].push_back(root->val);
        
        // Standard practice: traverse left before right
        recursion(root->left, ans, row + 1, col - 1);
        recursion(root->right, ans, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> ans;
        recursion(root, ans, 0, 0);
        vector<vector<int>> vec;
        
        for (auto ele : ans) {
            vector<int> sc;
            for (auto exl : ele.second) {
                sort(exl.second.begin(), exl.second.end());
                for (auto ee : exl.second) {
                    sc.push_back(ee);
                }
            }
            vec.push_back(sc);
        }
        return vec;
    }
};