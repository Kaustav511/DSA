#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
    node(int val){
        data=val;
        right=left=NULL;
    }
};
class sol{
    public:

    vector<int> postorder(node * root){
        vector<int> res;
        if(root==NULL)return res;
        stack<node*> s1,s2;
        if(root!=NULL){
            s1.push(root);
        }
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left != NULL){
                s1.push(root->left);
            }
            if(root->right != NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top()->data);
            s2.pop();
        }
    }
};

int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    sol s;
    vector<int> ans=s.postorder(root);
    cout<<"Post-Order traversal in Iterative way: "<<endl;

    for(auto it:ans){
        cout<<it<<" ";
    }
return 0;
}