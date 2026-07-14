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

    TreeNode* solve(vector<int>& postorder , int postStart , int postEnd , vector<int>& inorder , int inStart , int inEnd , unordered_map<int,int>& mpp){

        if(postStart < postEnd  ||  inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postStart]);

        int idx = mpp[root -> val];
        int rightSize = inEnd - idx;

        root -> right = solve(postorder , postStart - 1 , postStart - rightSize , inorder , idx + 1 , inEnd , mpp);

        root -> left = solve(postorder , postStart - rightSize - 1 , postEnd , inorder , inStart , idx - 1 , mpp);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int , int>mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }


        TreeNode* root = solve(postorder , postorder.size() - 1 , 0 , inorder , 0 , inorder.size() - 1 , mpp);

        return root;
    }
};