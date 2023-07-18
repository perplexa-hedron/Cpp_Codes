#include <iostream>
#include <map>
#include <vector>
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
        left = right = NULL;
    }
};
void buildTree(node *&root)
{
    string left, right;
    int d;
    cin >> d;
    root = new node(d);
    cin >> left;
    if (left == "true")
    {
        buildTree(root->left);
    }
    cin >> right;
    if (right == "true")
    {
        buildTree(root->right);
    }
}

void lOrder(node *root, int level, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }

    mp[level].push_back(root->data);

    lOrder(root->left, level + 1, mp);
    lOrder(root->right, level + 1, mp);
}

int main()
{
    node *root1 = NULL;
    buildTree(root1);
    map<int, vector<int>> mp;
    lOrder(root1, 0, mp);

    int height = mp.size();
    cout << "[";
    for (int i = 0; i < height - 1; i++)
    {
        cout << "[";
        for (int j = 0; j < mp[i].size() - 1; j++)
        {
            cout << mp[i][j] << ", ";
        }
        cout << mp[i][mp[i].size() - 1];
        cout << "], ";
    }

    cout << "[";
    for (int j = 0; j < mp[height - 1].size() - 1; j++)
    {
        cout << mp[height - 1][j] << ", ";
    }
    cout << mp[height - 1][mp[height - 1].size() - 1];
    cout << "]";

    cout << "]";

    return 0;
}