// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     void calSum(TreeNode* root , int& sum){

//         if(root == NULL){
//             return;
//         }

//         sum = sum + root -> val;

//         calSum(root -> left , sum);
//         calSum(root -> right , sum);
//     }

//     bool checkBST(TreeNode* root , long long mini , long long maxi){

//         if(root == NULL){
//             return true;
//         }

//         if(root -> val <= mini || root -> val >= maxi){
//             return false;
//         }

//         bool isLeft = checkBST(root -> left , mini , root -> val);
//         bool isRight = checkBST(root -> right , root -> val , maxi);

//         return isLeft && isRight;
//     }


//     void solve(TreeNode* root , int& ans){

//         if(root == NULL){
//             return;
//         }

//         if(checkBST(root , LLONG_MIN , LLONG_MAX)){
//             int sum = 0;
//             calSum(root , sum);
//             ans = max(ans , sum);
//         }

//         solve(root -> left , ans);
//         solve(root -> right , ans);
//     }


//     int maxSumBST(TreeNode* root) {

//         if(root == NULL){
//             return 0;
//         }


//         int ans = INT_MIN;
//         solve(root , ans);

//         return max(0 , ans);
//     }
// };


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


class NodeValue {

    public:
        int sum;
        int minValue;
        int maxValue;

        NodeValue(int sum , int minValue , int maxValue){
            this -> sum = sum;
            this -> minValue = minValue;
            this -> maxValue = maxValue;
        }
};


class Solution {
public:
    
    NodeValue solve(TreeNode* root , int& maxSum){

        if(root == NULL){
            return NodeValue(0 , INT_MAX , INT_MIN);
        }

        auto Left = solve(root -> left , maxSum);
        auto Right = solve(root -> right , maxSum);

        if(root -> val > Left.maxValue  &&  root -> val < Right.minValue){

            maxSum = max(maxSum , Left.sum + Right.sum + root -> val);
            
            return NodeValue(Left.sum + Right.sum + root -> val , min(root -> val , Left.minValue) , max(root -> val , Right.maxValue));
        }

        return NodeValue(0, INT_MIN , INT_MAX);
    }


    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root , maxSum);
        return maxSum;
    }
};