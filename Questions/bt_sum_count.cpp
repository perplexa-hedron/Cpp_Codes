#include <iostream>
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
int count(node * root){
    if(root == NULL){
        return 0;
    }
    return 1+ count(root->left) + count(root->right);
}
int sum(node *root){
    if(root == NULL){
        return 0;
    }
    return (root->data) + sum(root->left) + sum(root->right);
}
int main()
{
    node *root = buildtree();
    cout<<count(root)<<" "<<sum(root);
    return 0;
}