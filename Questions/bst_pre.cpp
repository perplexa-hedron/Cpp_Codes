#include <iostream>
#include <queue>
#include <climits>
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
        left = nullptr;
        right = nullptr;
    }
};
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
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
ostream &operator<<(ostream &os, node *root)
{
    bfs_lines(root);
    return os;
}
node *insert_bst(node *root, int data)
{
    if (root == nullptr)
    {
        return new node(data);
    }
    if (data <= root->data)
    {
        root->left = insert_bst(root->left, data);
    }
    else
    {
        root->right = insert_bst(root->right, data);
    }
    return root;
}
node *build()
{
    int d;
    cin >> d;
    node *root = nullptr;
    while (d != -1)
    {
        root = insert_bst(root, d);
        cin >> d;
    }
    return root;
}
static node *root;
node *formbst(node * root,int data)
{
    if(root == nullptr){
        root = new node(data);
    }
    if(root->data > data){
        root ->left = formbst(root->left,data);
    }
    if(root->data < data){
        root->right = formbst(root->right,data);
    }
    return root;
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    node * root = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for(int i =0;i<n;i++){
        root = formbst(root,pre[i]);
    }
    cout<<root;
}