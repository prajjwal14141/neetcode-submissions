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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return {};
        ans.push_back({root->val});
        q.push(root);
        int i = 1;

        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
                TreeNode* src = q.front();
                q.pop();
                if(src->left){
                    temp.push_back(src->left->val);
                    q.push(src->left);
                }
                if(src->right){
                    temp.push_back(src->right->val);
                    q.push(src->right);
                }
            }
            if(i++ % 2) reverse(temp.begin(), temp.end());
            if(!temp.empty())   ans.push_back(temp);
        }
        return ans;
    }
};