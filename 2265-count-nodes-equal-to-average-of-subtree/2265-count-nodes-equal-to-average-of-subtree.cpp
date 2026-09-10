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

    int cnt = 0;
    // pair<int,int> -> number of nodes in that subtree and the sum of values of that subtree
    pair<int,int> numofnodes(TreeNode* root){

        if(root == nullptr){
            return {0,0};
        }

        pair<int,int> left = numofnodes(root->left);

        pair<int,int> right = numofnodes(root->right);

        // calculate avg for that subtree and check if its equal to that roots value or not
        int nodes = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;
        int average = sum/nodes;
        if(average == root->val ) cnt++;

        return {nodes,sum};

    }




    int averageOfSubtree(TreeNode* root) {
        
        numofnodes(root);
        return cnt;
    }
};