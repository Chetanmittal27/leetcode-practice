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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);

        vector<double>ans;

        while(!q.empty()){

            int n = q.size();

            double calc = 0;

            for(int i = 0; i < n; i++){

                auto node = q.front();
                q.pop();

                calc = calc + node -> val;

                if(node -> left != NULL){
                    q.push(node -> left);
                }

                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }

            ans.push_back(calc / n);
        }

        return ans;
    }
};