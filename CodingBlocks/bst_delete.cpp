#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        right = nullptr;
    }
};
node *buildfromarray(vector<int> arr, int s, int e) // Builds the tree from an array as in-build type
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
void printpre(node * root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}
int main()
{

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i =0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        queue <int> q;
        int no;
        cin>>no;
        while(no--){
            int data;
            cin>>data;
            q.push(data);
        }
        for(std::vector<int>::iterator it = vec.begin(); it != vec.end();){
            if(*it == q.front()){
                vec.erase(it);
                q.pop();
            }
            else{
                it++;
            }
        }
        printpre(buildfromarray(vec,0,vec.size()-1));
        cout<<endl;
    }
    return 0;
}