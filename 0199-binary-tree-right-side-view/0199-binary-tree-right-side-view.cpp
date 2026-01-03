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
int count(TreeNode* root ) {
    if(!root) return 0;
    return (1+ max(count(root->left) , count(root->right ))) ;

}
void  calling (TreeNode* root , int level , vector<int> &res , vector<bool> &vis) {
    if(!root ) return ;
    if(!vis[level]) {
        res.push_back(root->val);
        vis[level] = true;

    }
        calling(root->right , level+1 , res, vis);
        calling(root->left , level+1 , res, vis);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res ;
        if(!root ) return res ;
        int total = count(root );
        vector<bool> vis(total , 0);

        calling(root , 0 , res  ,vis);
        return res;
    }
};