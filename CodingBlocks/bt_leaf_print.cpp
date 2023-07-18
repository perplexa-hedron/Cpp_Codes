#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* levelbuild()
{
    int d;
    cin >> d;
    node* root = new node(d);
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }

        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }

    return root;
}
void bfs_lines(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}
void leafprint(node * root){
    if(root->left == nullptr && root ->right == nullptr){
        cout<<root->data<<" ";
        return;
    }
    leafprint(root->left);
    leafprint(root->right);
}
int main()
{
    node *root = levelbuild();
    bfs_lines(root);
    // leafprint(root);
    return 0;
}