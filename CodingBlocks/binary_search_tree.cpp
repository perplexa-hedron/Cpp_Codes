#include <iostream>
#include <queue>
#include <climits>
#include<string>
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
        right = nullptr;
    }
};
class ll
{
public:
    node *head;
    node *tail;
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
node *buildfromarray(int arr[], int s, int e) // Builds the tree from an array as in-build type
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildfromarray(arr, s, mid - 1);
    root->right = buildfromarray(arr, mid + 1, e);

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
bool search(node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key <= root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
bool check(node *root, int minv = INT_MIN, int maxv = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }
    if ((root->data >= minv && root->data <= maxv) && (check(root->left, minv, root->data) && check(root->right, root->data, maxv)))
    {
        return true;
    }
    return false;
}
node *deletebst(node *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (data < root->data)
    {
        root->left = deletebst(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        // found the node to delete among the three cases
        // 1. node with no child - leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 2.root with one child
        if (root->left != nullptr && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            ;
            delete root;
            return temp;
        }
        // 3.case with 2 children
        node *replace = root->right;
        // finding the next successor from right subtree
        while (replace->left != nullptr)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deletebst(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deletebst(root->right, data);
        return root;
    }
}
ll flatten(node *root)
{
    ll l;
    if (root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }
    // only leaf node
    if (root->right == nullptr && root->left == nullptr)
    {
        l.head = l.tail = root;
        return l;
    }
    // left is not null
    if (root->left != nullptr && root->right == nullptr)
    {
        ll leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }
    if (root->right != nullptr && root->left == nullptr)
    {
        ll rightll = flatten(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }
    ll leftll = flatten(root->left);
    ll rightll = flatten(root->right);

    leftll.tail->right = root;
    root->right = rightll.head;
    l.head = leftll.head;
    l.tail = rightll.tail;
    return l;
}
int sum = 0;
void replacegrsum(node *&root) // replaces all smaller nodes with sum of all greater nodes
{

    if (root == NULL)
    {
        return;
    }

    replacegrsum(root->right);
    root->data = root->data + sum; // Need to make a global sum variable and initialize it to 0
    sum = root->data;
    replacegrsum(root->left);
}
int main()
{
    // node *root = build();
    // int key;
    // cin >> key;
    // inorder(root);
    // cout<<endl;
    // root = deletebst(root,key);
    // inorder(root);cout<<endl;
    // bfs_lines(root);
    // if(check(root)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }
    // printpre(root);
    // ll l = flatten(root);
    // node * temp = l.head;
    // while(temp->right != NULL){
    //     cout<<temp->data<<"-->";
    //     temp = temp->right;
    // }
    // cout<<temp->data<<endl;
    // cout<<t;
    // node *root = nullptr;
    int n;
    cin >> n;
    // cout<<n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node * root = buildfromarray(arr,0,n-1);
    // replacegrsum(root);
    // printpre(root);
    bfs_lines(root);
    return 0;
}