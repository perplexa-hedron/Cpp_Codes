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
int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
node* levelbuild()      //To build the tree levelwise
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
node *buildtree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
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
ostream &operator<<(ostream &os, node *root)
{
    bfs_lines(root);
    return os;
}
istream &operator>>(istream & is, node *&root){
    root = buildtree();
    return is;
}
void right_view(node * root,int level,int &max_level){
    if(root == nullptr){
        return;
    }
    if(max_level < level){
        cout<<root->data<<" ";
        max_level = level;
    }
    right_view(root->left,level+1,max_level);
    right_view(root->right,level+1,max_level);
}
int main()
{
    node * root = levelbuild();
    // cout<<root<<endl;
    int maxlevel = -1;
    right_view(root,0,maxlevel);
    return 0;
}