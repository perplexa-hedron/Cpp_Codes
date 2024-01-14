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
class hbpair
{
public:
    int height;
    bool balance;
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
hbpair hbalanced(node *root)
{
    hbpair p;
    if (root == nullptr){
        p.height =0;
        p.balance = true;
        return p;
    }
    hbpair left = hbalanced(root->left);
    hbpair right = hbalanced(root->right);
    p.height = max(left.height,right.height)+1;
    if(abs(left.height - right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}
int main()
{
    node *root = form();
    if(hbalanced(root).balance){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}