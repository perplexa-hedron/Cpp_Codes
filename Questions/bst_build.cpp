#include <iostream>
#include <queue>
#include <climits>
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
void printpre(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
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
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[1000];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        printpre(buildfromarray(arr,0,n-1));
        cout<<endl;
    }
    return 0;
}