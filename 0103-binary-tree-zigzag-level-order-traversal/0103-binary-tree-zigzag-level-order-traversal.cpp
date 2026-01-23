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
        vector<vector<int>> res ;
        if(!root )return res ;
        bool is = true ;
        queue<TreeNode * > q ;
        q.push(root );
        while(!q.empty()) 
        {
            int n = q.size();
            vector<int > need ;
            int cnt =0 ;
            if(n)
            while(cnt < n ) {
                TreeNode * temp = q.front();
                q.pop();
                need.push_back(temp->val );
                if(temp->left ) q.push(temp->left );
                if(temp->right) q.push(temp->right);
                cnt++;
            }
            if(!is) reverse(need.begin()  , need.end());
            res.push_back(need );
            is = !is ;
        }
        return res ;

        
    }
};