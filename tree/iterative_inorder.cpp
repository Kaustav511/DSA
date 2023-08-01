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
class sol{
    public:
    vector<int> inorder(node*root){
        vector<int> res;
        
        stack<node*> st;
        
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty()==true)break;
                root=st.top();
                st.pop();
                res.push_back(root->data);
                root=root->right;
            }
        }
        return res;
    }
};

int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    sol s;
    vector<int> ans=s.inorder(root);
    cout<<"In-Order traversal in Iterative way: "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
return 0;
}