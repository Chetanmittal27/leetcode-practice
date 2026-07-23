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

    void findInorder(TreeNode* root , vector<int>& arr){

        if(root == NULL){
            return;
        }

        findInorder(root -> left , arr);
        arr.push_back(root -> val);
        findInorder(root -> right , arr);
    }


    bool findTarget(TreeNode* root, int k) {
        
        vector<int>arr;

        findInorder(root , arr);

        int l = 0 , r = arr.size() - 1;

        while(l < r){

            if((arr[l] + arr[r]) == k){

                return true;
            }

            else if((arr[l] + arr[r]) < k){

                l++;
            }

            else{

                r--;
            }
        }

        return false;
    }
};