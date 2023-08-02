//own
/*
    as if the givven tree is bst then after the inorder traversal if all the nodes of the tree is sorted order then we can say that the givven tree is a BST.

    *)so a function help() to traverse the tree in in-order.it take the root of the tree and a data-structure to store the node value of the tree.

    *) And a issorted() to check that after in-order traversal the node values are in sorted manner.it take a data-structure that contain the node values. 

    so the time complexcity is -> O(n)+O(m) == O(n) [n = number of nodes in a tree in inorder function, m = size of the vector in issorder function].

    the space complexcity is -> O(n) [the stacks space and in the wrost case condition for the size of the vector O(n)].

    code-link -> https://leetcode.com/problems/validate-binary-search-tree/
                https://practice.geeksforgeeks.org/problems/check-for-bst/1
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // int nonode(TreeNode* root){
    //     if(root == NULL)return 0;
    //     return 1+nonode(root->left)+nonode(root->right);
    // }
    bool issorted(vector<int>& v){
        if(equal(v.begin()+1,v.end(),v.begin())) return false;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] <= v[i - 1]) {
                return false;
            }
        }
        return true;
    }
    void inorder(TreeNode* root ,vector<int> &v){
        if(root == nullptr){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        // int n=nonode(root);
        // if(n == 1)return true;
        if(root != nullptr && root->left == nullptr && root->right == nullptr){
            return true;
        }
        vector<int> v;
        inorder(root,v);
        return issorted(v);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solution;
    bool isValid = solution.isValidBST(root);

    if (isValid) {
        cout << "The given binary tree is a valid binary search tree." << endl;
    } else {
        cout << "The given binary tree is not a valid binary search tree." << endl;
    }

    // Clean up memory (not strictly necessary, but good practice)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------
/*
    tak u forward



#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return help(root,INT_MIN,INT_MAX);
    }
    bool help(Node* root, int min_val,int max_val){
        if(root == NULL)return true;
        if(root->data >= max_val || root->data <= min_val)return false;
        return help(root->left,min_val,root->data) and help(root->right,root->data,max_val);
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


// } Driver Code Ends
*/