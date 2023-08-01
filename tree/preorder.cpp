// this is recursion approch.
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<< root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    cout<<"Pre=Order traversal is: "<<endl;
    preorder(root);
return 0;
}