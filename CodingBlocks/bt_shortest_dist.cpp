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
//finding the level of the given node from any other given node
int search(node *root, int key, int level)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root->data == key)
    {
        return level;
    }
    //searching in left
    if (search(root->left, key, level + 1) != -1)
    {
        return search(root->left, key, level + 1);
    }
    //if not found in left then returning right
    return search(root->right, key, level + 1);
}
//function to find distance between two nodes
int dist(node *root, int a, int b)
{
    return search(lca(root, a, b), a, 0) + search(lca(root, a, b), b, 0);
}
int main()
{
    node *root = nullptr;
    cin >> root;
    cout << root;
    cout << dist(root, 1, 9);
}