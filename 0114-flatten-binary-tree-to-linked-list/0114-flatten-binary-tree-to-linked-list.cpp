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

    void preorder(TreeNode* root , vector<int>& ans){
        if(root == NULL){
            return;
        }

        ans.push_back(root -> val);
        preorder(root -> left , ans);
        preorder(root -> right , ans);
    }

    
    void createLL(vector<int>& ans , TreeNode* root){
        TreeNode* mover = root;
        mover -> left = NULL;

        for(int i = 1; i < ans.size(); i++){
            TreeNode* temp = new TreeNode(ans[i]);
            mover -> right = temp;
            mover = temp;
            mover -> left = NULL;
        }
    }

    void flatten(TreeNode* root) {

        if(root == NULL) return;
        
        vector<int>ans;
        preorder(root , ans);

        createLL(ans , root);
    }
};