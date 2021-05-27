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
    void sumOfLeftLeavesUtil(TreeNode* node, char parent, int *res){
        if(node->left == NULL && node->right == NULL){
            if(parent == 'l')
                (*res) += node->val;
        }
        else{
            if(node->left != NULL)
                sumOfLeftLeavesUtil(node->left,'l',res);
            if(node->right != NULL)
                sumOfLeftLeavesUtil(node->right,'r',res);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        sumOfLeftLeavesUtil(root,'r',&res);
        return res;
    }
};