#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class sol
{
public:
    vector<vector<int>> levelorder(node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                node *nn = q.front();
                q.pop();
                if (nn->left != NULL)
                    q.push(nn->left);
                if (nn->right != NULL)
                    q.push(nn->right);
                res.push_back(nn->data);
            }
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    sol s;
    vector<vector<int>> res = s.levelorder(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        // cout<<endl;
    }
    return 0;
}