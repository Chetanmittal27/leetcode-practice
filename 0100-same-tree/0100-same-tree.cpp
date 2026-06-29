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

    int solve(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL){
            return 0;
        }

        if(p != NULL && q == NULL) return -1;
        if(p == NULL && q != NULL) return -1;

        if(p -> val != q -> val) return -1;

        int leftPart = solve(p -> left , q -> left);
        if(leftPart == -1){
            return -1;
        }

        int rightPart = solve(p -> right , q -> right);
        if(rightPart == -1){
            return -1;
        }
        
        if(leftPart == -1 || rightPart == -1) return -1;
        return 0;
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL && q == NULL){
            return true;
        }

        int val = solve(p , q);
        
        if(val == -1) return false;
        return true;
    }
};