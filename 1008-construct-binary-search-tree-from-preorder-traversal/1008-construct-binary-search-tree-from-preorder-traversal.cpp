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

    TreeNode* createBST(vector<int>& preorder , vector<int>& inorder , int preStart , int preEnd , int inStart , int inEnd , unordered_map<int,int>& mpp){

        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }


        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = mpp[root -> val];
        int leftSize = idx - inStart;

        root -> left = createBST(preorder , inorder , preStart + 1 , preStart + leftSize , inStart , idx - 1 , mpp);

        root -> right = createBST(preorder , inorder , preStart + leftSize + 1 , preEnd , idx + 1 , inEnd , mpp);

        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int>temp(preorder.begin() , preorder.end());

        sort(preorder.begin() , preorder.end());

        vector<int>inorder(preorder.begin() , preorder.end());


        unordered_map<int,int>mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = createBST(temp , inorder , 0 , preorder.size() - 1 , 0 , inorder.size() - 1 , mpp);

        return root;
    }
};