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
node * create(int * inor,int *preor,int s,int e){
    static int i=0;
    if(s>e){
        return nullptr;
    }
    node * root = new node(preor[i]);
    int idx =-1;
    for(int j = s;j<=e;j++){
        if(inor[i] == preor[j]){
            idx =j;
            break;
        }
    }
    i++;
    root->left = create(inor,preor,s,idx-1);
    root->right = create(inor,preor,idx +1,e);

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
    int n;
    cin>>n;
    int preor[n];
    for(int i =0;i<n;i++){
        cin>>preor[i];
    }
    int inor[n];
    for(int i =0;i<n;i++){
        cin>>inor[i];
    }
    // node * root = create(inor,preor,0,n-1);
    // print(create(inor,preor,0,n-1));
    return 0;
}