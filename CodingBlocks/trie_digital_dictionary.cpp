#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class node{
    public:
    char data;
    unordered_map<char,node * > next;
    bool terminates;
    node(char d)
    {
        data = d;
        terminates = false;
    }
};
class trie{
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
            if (temp->next.count(ch))
            {
                cnt++;
                temp = temp->next[ch];
            }
            else
            {
                node *n = new node(ch);
                cnt++;
                temp->next[ch] = n;
                temp = n;
            }
        }
        temp->terminates = true;
    }
    string find(char *w)
    {
        string ans="";
        node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->next.count(ch) == 0)
            {
                return "No suggestions";
            }
            else{
                ans+=ch;
                temp = temp->next[ch];
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    char 
    return 0;
}