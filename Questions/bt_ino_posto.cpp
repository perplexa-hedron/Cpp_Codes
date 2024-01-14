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
node* buildfromarray (int arr[], int s, int e)  //Builds the tree from an array as in-build type
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node (arr[mid]);
    root->left = buildfromarray (arr, s, mid-1);
    root->right = buildfromarray (arr, mid+1, e);

    return root;
}
void print(node * root){
    if(root == nullptr){
        return;
    }
    if(root ->left == nullptr){
        cout <<"END";
    }
    else{
        cout<<root->left->data;
    }
    cout<<" => "<<root->data<<" <= ";
    if(root ->right == nullptr){
        cout <<"END";
    }
    else{
        cout<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);

}
int main()
{
    int n,m;
    cin>>n;
    int posto[n];
    for(int i =0;i<n;i++){
        cin>>posto[i];
    }
    cin>>m;
    int inor[m];
    for(int i =0;i<m;i++){
        cin>>inor[i];
    }
    // node * root = create(inor,posto,0,n-1);
    print(buildfromarray(inor,0,n-1));
    return 0;
}