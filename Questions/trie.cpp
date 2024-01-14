#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
/*
class node
{
public:
    char data;
    unordered_map<char, node *> children;
    bool terminal;
    node(char d)
    {
        data = d;
        terminal = false;
    }
};

class trie
{
    node *root;
    int cnt;

public:
    trie()
    {
        root = new node('\0');
        cnt = 0;
    }
    void insert(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0';i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                node *n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};
*/

//class for max_xor
class node{
public : 
node * left; //for 0
node * right; //for 1
};

class trie{
    node * root;
    public:
    trie(){
        root = new node();
    }
    //insert function
    void insert(int n){
        node * temp = root;
        for(int i = 31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit ==0){
                if(temp->left == nullptr){
                    temp ->left = new node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == nullptr){
                    temp ->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int xor_help(int value){
        node* temp = root;
        int curr_ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (value>>i)&1;
            if(bit ==0){
                if(temp ->right != nullptr){
                    temp=temp->right;
                    curr_ans+=(1<<i);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left != nullptr){
                    temp = temp->left;
                    curr_ans+=(1<<i);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return curr_ans;
    }
    int max_xor(vector<int> input,int n){
        int max_xor = 0;
        for(int i =0;i<n;i++){
            int val = input[i];
            insert(val);
            int curr_xor = xor_help(val);
            max_xor = max(curr_xor,max_xor);
            // cout<<max_xor<<endl;
        }
        return max_xor;
    }
};

int main()
{

    
    //maximum xor
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i =0;i<n;i++){
        cin>>input[i];
    }
    trie t;
    cout<<t.max_xor(input,n)<<endl;
    

    //word present or not
    // trie t;
    // char words[][10]= {"a","hello","not","news","apple"};
    // char w[10];
    // cin>>w;
    // for(int i =0;i<5;i++){
    //     t.insert(words[i]);
    // }
    // if(t.find(w)){
    //     cout<<"present";
    // }
    // else{
    //     cout<<"absent";
    // }
    return 0;
}