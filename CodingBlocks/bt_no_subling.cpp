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
void siblings(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->right != nullptr && root->left == nullptr)
    {
        cout << root->right->data << " ";
    }
    if (root->right == nullptr && root->left != nullptr)
    {
        cout << root->left->data << " ";
    }
    siblings(root->left);
    siblings(root->right);
}
int main()
{
    node *root = form();
    siblings(root);
    return 0;
}