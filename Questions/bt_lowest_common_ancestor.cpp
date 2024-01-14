#include <iostream>
#include <string>
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
node *form()
{
    string s;
    cin >> s;
    if (s == "false")
    {
        return nullptr;
    }
    else if (s == "true")
    {
        cin >> s;
    }
    node *root = new node(stoi(s));
    root->left = form();
    root->right = form();
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
istream &operator>>(istream &is, node *&root)
{
    root = buildtree();
    return is;
}
node *lca(node *root, int a, int b)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == a || root->data == b)
    {
        return root;
    }
    node *left = lca(root->left, a, b);
    node *right = lca(root->right, a, b);
    if (left != nullptr && right != nullptr)
    {
        return root;
    }
    if (left != nullptr)
    {
        return left;
    }
    return right;
}
class Pair
{
public:
    int maxsum;
    int branchsum;
    Pair()
    {
        branchsum = 0;
        maxsum = 0;
    }
};
Pair max_sum(node * root){
    Pair p;
    if(root == nullptr){
        return p;
    }
    Pair left = max_sum(root->left);
    Pair right = max_sum(root->right);

    int op1 = root->data;
    int op2 = root->data + left.branchsum;
    int op3 = root->data + right.branchsum;
    int op4 = root->data+ left.branchsum+right.branchsum;

    int curr = max(op1,max(op2,max(op3,op4)));
    p.branchsum = max(left.branchsum,max(right.branchsum,0))+root->data;
    p.maxsum = max(left.maxsum,max(right.maxsum,curr));
    return p;
}
int main()
{
    node *root = buildtree();
    // int a,b;
    bfs_lines(root);
    // cin>>a>>b;
    // cout<<lca(root,a,b)->data;
    // cout << root;
    // cout << max_sum(root).maxsum<<endl;
}