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
node *leaves_delete(node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return nullptr;
    }

    root->left = leaves_delete(root->left);
    root->right = leaves_delete(root->right);
    return root;
}
void end_leaves(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == NULL)
    {
        cout << "END";
    }
    else
    {
        cout << root->left->data;
    }
    cout << " => " << root->data << " <= ";
    if (root->right == NULL)
    {
        cout << "END";
    }
    else
    {
        cout << root->right->data;
    }
    cout << endl;
    end_leaves(root->left);
    end_leaves(root->right);
    return;
}
int main()
{
    node *root = form();
    root = leaves_delete(root);
    end_leaves(root);
    return 0;
}