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
    void solve1(vector<int>&ans1,TreeNode* root){
        if(root==NULL)return;
        if(root->right==NULL && root->left==NULL)ans1.push_back(root->val);
        solve1(ans1,root->left);
        solve1(ans1,root->right);
    }
    void solve2(vector<int>&ans2,TreeNode* root){
        if(root==NULL)return;
        if(root->right==NULL && root->left==NULL)ans2.push_back(root->val);
        solve1(ans2,root->left);
        solve1(ans2,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        solve1(ans1,root1);
        solve2(ans2,root2);
        if(ans1==ans2)return true;
        return false;
    }
};
