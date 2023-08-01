#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void display(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    cout<<"The tree is: "<<endl;
    display(root);
return 0;
}
