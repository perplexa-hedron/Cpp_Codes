#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void headinsert(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;
    n->next = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}
void print(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
node *present(node *head, int data)
{
    node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    if (temp->data == data)
    {
        return temp;
    }
    return NULL;
}
void nodedelete(node *&head, int data)
{
    node *dl = present(head, data);
    if (dl == NULL)
    {
        return;
    }
    if(head == dl){
        head = head->next;
    }
    node *temp = head;
    while (temp->next != dl)
    {
        temp = temp->next;
    }
    temp->next = dl->next;
    delete dl;
}
int main()
{
    node *head = NULL;
    headinsert(head, 10);
    headinsert(head, 20);
    headinsert(head, 30);
    headinsert(head, 40);
    headinsert(head, 50);
    print(head);
    nodedelete(head, 40);
    print(head);
    return 0;
}