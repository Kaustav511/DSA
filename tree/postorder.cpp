#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}
int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    cout<<"Post-Order traversal is: "<<endl;
    postorder(root);
return 0;
}