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

 int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh,rh);
    }

void findmaxdia(TreeNode* root,int& maxi){
         if(root == nullptr){
            return;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        maxi = max(maxi,lh+rh);

        findmaxdia(root->left,maxi);

        findmaxdia(root->right,maxi);
}

    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = 0;

       findmaxdia(root,maxi);

       return maxi;


    }
};