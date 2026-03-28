class Solution {
public:

    TreeNode* search(TreeNode* root, int key) {
        TreeNode* temp = root;
        if(!root) return nullptr;

        // if root itself is key → no parent
        if(root->val == key) return nullptr;

        while(temp) {
            if(key < temp->val) {
                if(temp->left && temp->left->val == key) return temp;
                temp = temp->left;
            }
            else if(key > temp->val) {
                if(temp->right && temp->right->val == key) return temp;
                temp = temp->right;
            }
            else break;
        }
        return nullptr;
    }

    TreeNode* findPred(TreeNode* root) {
        while(root->right) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        // 🔥 CASE: root itself is target
        if(root->val == key) {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* pred = findPred(root->left);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
            return root;
        }

        TreeNode* pnode = search(root, key);
        if(pnode == nullptr) return root;

        TreeNode* keynode = nullptr;

        if(key < pnode->val) keynode = pnode->left;
        else keynode = pnode->right;

        if(!keynode) return root;

        // 🔥 CASE 1: no left child
        if(!keynode->left) {
            TreeNode* child = keynode->right;

            if(pnode->left == keynode) pnode->left = child;
            else pnode->right = child;

            delete keynode;
        }

        // 🔥 CASE 2: no right child
        else if(!keynode->right) {
            TreeNode* child = keynode->left;

            if(pnode->left == keynode) pnode->left = child;
            else pnode->right = child;

            delete keynode;
        }

        // 🔥 CASE 3: two children
        else {
            TreeNode* pred = findPred(keynode->left);
            int val = pred->val;

            keynode->val = val;
            keynode->left = deleteNode(keynode->left, val);
        }

        return root;
    }
};