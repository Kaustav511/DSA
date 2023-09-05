
//  * Definition for a binary tree node.
#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution{
    public:
        TreeNode* help(TreeNode* root){
            if(!root->left)return root->right;
            else if(!root->right)return root->left;
            TreeNode* rightChild=root->right;
            TreeNode* leftRight=findRight(root->left);
            leftRight->right=rightChild;
            return root->left;
        }
        TreeNode* findRight(TreeNode* root){
            if(!root->right)return root;
            return findRight(root->right);
        }
        TreeNode* deleteNode(TreeNode* root, int key){
            if(!root)return NULL;
            if(root->val == key)return help(root);
            TreeNode* temp=root;
            while(root){
                if(root->val > key){
                    if(root->left and root->left->val == key){
                        root->left=help(root->left);
                    }
                    else{
                        root=root->left;
                    }
                }
                else{
                    if(root->right and root->right->val == key){
                        root->right=help(root->right);
                    }
                    else{
                        root=root->right;
                    }
                }
            }
            return temp;
        }
 };
 void inorderTraversal(TreeNode* root) {
    if (root) {
        // Traverse the left subtree
        inorderTraversal(root->left);

        // Print the current node's value
        std::cout << root->val << " ";

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}
 int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution solution;

    // Delete a node with a specific value (e.g., 3)
    int key_to_delete = 3;
    TreeNode* new_root = solution.deleteNode(root, key_to_delete);

    // Print the resulting tree to verify the deletion
    cout << "Binary Search Tree after deleting " << key_to_delete << ":\n";
    inorderTraversal(new_root);
    cout << std::endl;
 }