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
int diameter(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}
pair<int,int> diameter_optimized(node * root){ 
    /*first = diameter
    second = height*/
    pair <int,int> p;
    if(root == nullptr){
        p.first = p.second = 0;
        return p;
    }
    pair <int,int> left = diameter_optimized(root->left);
    pair <int,int> right = diameter_optimized(root->right);

    p.second = max(left.second,right.second)+1;
    p.first = max(left.second+right.second,max(left.first,right.first));
    return p;
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
int main()
{
    node *root = buildtree();
    cout<<diameter(root)<<endl;
    pair <int,int> p = diameter_optimized(root);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}