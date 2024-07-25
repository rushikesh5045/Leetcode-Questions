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
  TreeNode * solve(vector<int>& nums,int l,int h)
    {
        if(l>h)
        {
            return nullptr;
        }
        int mid = l+(h-l)/2;
        TreeNode * t = new TreeNode(nums[mid]);
        t->left = solve(nums,l,mid-1);
        t->right = solve(nums,mid+1,h);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int mid = l+(h-l)/2;
        TreeNode * t = new TreeNode(nums[mid]);
        t->left = solve(nums,l,mid-1);
        t->right = solve(nums,mid+1,h);
        return t;
    }
};
