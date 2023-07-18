#include <iostream>
#include <queue>
#include <string>
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
void printpre(node *root) // preorder
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
}
void printin(node *root) // inorder
{
    if (root == NULL)
    {
        return;
    }
    printin(root->left);
    cout << root->data << " ";
    printin(root->right);
}
void printpost(node *root) // postorder
{
    if (root == NULL)
    {
        return;
    }
    printpost(root->left);
    printpost(root->right);
    cout << root->data << " ";
}
void printkthlevel(node *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printkthlevel(root->left, k - 1);
    printkthlevel(root->right, k - 1);
    return;
}
void printlevel(node *root)
{

    for (int i = 1; i <= height(root); i++)
    {
        printkthlevel(root, i);
    }
    return;
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
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
    return;
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
pair <int,int> height_level(node * root){
    pair <int,int>p;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            p.first++;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            p.second++;
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
    return p;
}
int main()
{
    node *root1 = form();
    node *root2 = form();
    pair <int,int> p1 = height_level(root1);
    pair <int,int> p2 = height_level(root2);
    if(p1.first == p2.first && p1.second == p2.second){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}