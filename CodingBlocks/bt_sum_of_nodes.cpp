#include <iostream>
#include <queue>
#include <vector>
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
// vector<int> vec;
void sum_path(node *root, vector <int> &vec)
{
    if (root == nullptr)
    {
        return;
    }
    vec.push_back(root->data);
    sum_path(root->left, vec);
    // vec.push_back(0);
    sum_path(root->right, vec);
    return;
}
int main()
{
    node *root = form();
    int value;
    cin >> value;
    // bfs_lines(root);
    vector<int> vec;
    sum_path(root, vec);
    for(int i = vec.size()-1;i>=0;i--){
        cout<<vec[i]<<" ";
    }
    return 0;
}