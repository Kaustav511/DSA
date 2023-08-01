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
            if(root==NULL){
                return res;
            }
            stack<node*>st;
            st.push(root);
            while(!st.empty()){
                root=st.top();
                st.pop();
                res.push_back(root->data);

                if(root->right != NULL){
                    st.push(root->right);
                }

                if(root->left!= NULL){
                    st.push(root->left);
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
    cout<<"Pre-Order traversal in Iterative way: "<<endl;
    for(auto it : ans){
        cout<<it<<" "; 
    }
return 0;
}