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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode* , long long>>q;
        q.push({root , 0});

        long long ans = 0;

        while(!q.empty()){

            int len = q.size();

            long long mini = -1;
            long long maxi = -1;

            long long first = q.front().second;


            for(int i = 0; i < len; i++){

                auto p = q.front();
                q.pop();

                auto node = p.first;
                long long pos = p.second;

                pos = pos - first;

                if(i == 0){
                    mini = pos;
                }

                if(i == len - 1){
                    maxi = pos;
                }


                if(node -> left != NULL){
                    q.push({node -> left , 2 * pos + 1});
                }

                if(node -> right != NULL){
                    q.push({node -> right , 2 * pos + 2});
                }
            }
            

            ans = max(ans , maxi - mini + 1);
        }

        return (int)ans;
    }
};