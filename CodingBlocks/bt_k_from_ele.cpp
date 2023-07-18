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
    buildtree();
    return is;
}
void kprint(node *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    kprint(root->left, k - 1);
    kprint(root->right, k - 1);
    return;
}
int dprint(node *root, node *target, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // rech the target node
    if (root == target)
    {
        kprint(target, k);
        return 0;
    }
    // next step ancestor
    int dl = dprint(root->left, target, k);
    if (dl != -1)
    {
        // again two cases
        // ancestor itself or you need to go to the right ancestor
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            kprint(root->right, k - 2 - dl);
        }
        return 1 + dl;
    }
    int dr = dprint(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            kprint(root->left, k - 2 - dr);
        }
        return 1 + dr;
    }
    // node was not present in the left as well as in the right
    return -1;
}
node *create(int *inor, int *preor, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return nullptr;
    }
    node *root = new node(preor[i]);
    int idx = -1;
    for (int j = s; j <= e; j++)
    {
        if (inor[i] == preor[j])
        {
            idx = j;
            break;
        }
    }
    i++;
    root->left = create(inor, preor, s, idx - 1);
    root->right = create(inor, preor, idx + 1, e);

    return root;
}
node *search(node *root, int data)
{
    node *temp = nullptr;
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == data)
    {
        return root;
    }
    if (search(root->left, data))
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
int main()
{
    int n;
    cin >> n;
    int preor[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preor[i];
    }
    int inor[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inor[i];
    }
    node *root = create(inor, preor, 0, n - 1);
    int t;
    cin >> t;
    while (t--)
    {
        int key, dist;
        cin >> key >> dist;
        node *target = search(root, key);
        if(dprint(root, target, dist)==-1){
            cout<<"0";
        }
        else{
            dprint(root, target, dist);
        }
        cout << endl;
    }
}