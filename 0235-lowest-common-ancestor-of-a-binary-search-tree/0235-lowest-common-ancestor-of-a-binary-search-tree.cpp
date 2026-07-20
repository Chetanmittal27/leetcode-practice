/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL){
            return NULL;
        }

        if(root -> val == p -> val || root -> val == q -> val){
            return root;
        }

        auto isLeft = lowestCommonAncestor(root -> left , p , q);
        auto isRight = lowestCommonAncestor(root -> right , p , q);

        if(!isLeft && !isRight){
            return NULL;
        }

        if(isLeft && isRight){
            return root;
        }

        if(isLeft) return isLeft;
        return isRight;
    }
};