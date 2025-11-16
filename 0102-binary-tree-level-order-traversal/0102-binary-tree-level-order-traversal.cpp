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
    vector<vector<int>> levelOrder(TreeNode* root) {
        using node = TreeNode ;

        vector<vector<int>> res ;
        if(root == nullptr ) return res ;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0; i<size;i++){
                node* newNode = q.front();
                q.pop();
                if(newNode-> left!= nullptr  ) q.push(newNode-> left );
                if(newNode-> right != nullptr ) q.push(newNode-> right);
                v.push_back(newNode-> val);

            }
            res.push_back(v);
        }
        return res ;

        
        
    }
};