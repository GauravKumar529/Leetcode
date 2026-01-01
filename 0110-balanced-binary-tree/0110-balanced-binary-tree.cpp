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
int height(TreeNode *root ) {
    if(!root ) return 0;
    return (1+ max(height(root->left) , height(root->right)));

}
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int h1 = 0 , h2 = 0;


        if(root->left) h1 = height(root->left);
        if(root->right ) h2 = height(root->right);


        if(abs(h1- h2)>1) {

            return 0;

        }
        return (isBalanced(root->left) &&  isBalanced(root->right));   ;





        
    }
};