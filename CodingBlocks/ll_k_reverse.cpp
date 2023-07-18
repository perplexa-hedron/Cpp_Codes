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
int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
void tail_insert(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}
void head_insert(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *x = new node(d);
    x->next = head;
    head = x;
}
void middle_insert(node *&head, int d, int p)
{
    if (head == NULL || p == 0)
    {
        head_insert(head, d);
        return;
    }
    else if (p > length(head))
    {
        tail_insert(head, d);
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
    cout << endl;
}
void head_delete(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}
void tail_delete(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *prev = head;
    while (prev->next != temp)
    {
        prev = prev->next;
    }
    delete temp;
    prev->next = NULL;
}
void middle_delete(node *&head, int n)
{
    if (n <= 0)
    {
        head_delete(head);
        return;
    }
    else if (n >= length(head))
    {
        tail_delete(head);
        return;
    }
    else
    {
        node *prev = head;
        int jump = 1;
        while (jump < n)
        {
            prev = prev->next;
            jump++;
        }
        node *x = prev->next;
        prev->next = x->next;
        delete x;
    }
}
int search(node *head, int key)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        // cnt++;
        if (temp->data == key)
        {
            return cnt;
        }
        cnt++;
        temp = temp->next;
    }
    return -1;
}
int research(node *head, int key, int cnt)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == key)
    {
        return cnt;
    }
    cnt++;
    return research(head->next, key, cnt);
}
node *input()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        tail_insert(head, d);
        cin >> d;
    }
    return head;
}
ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}
istream &operator>>(istream &is, node *&head)
{
    head = input();
    return is;
}
void reverse(node *&head)
{
    node *c = head;
    node *p = NULL;
    node *n;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
}
node *recursive_reverse(node *&head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    node *shead = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}
node *midpoint(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *kth(node *head, int k)
{
    node *slow = head;
    node *fast = head;
    while (k > 0)
    {
        fast = fast->next;
        k--;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
node *merge(node*a,node*b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node *c;
    if(a->data <b->data){
        c=a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}
node*mergesort(node *&head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid ->next;
    mid ->next = NULL;
    a = mergesort(a);
    b = mergesort(b);
    return merge(a,b);
}
bool cycle(node *head){
    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast ->next != NULL){
        fast = fast ->next->next;
        slow = slow ->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
node *removecycle(node *&head){
    node * slow= head;
    node * fast = head;
    while(fast != NULL && fast ->next != NULL){
        fast = fast ->next->next;
        slow = slow ->next;
        if(fast == slow){
            // slow = head;
            break;
        }
    }
    if(slow!=fast){
        return NULL;
    }
    slow = head;
    while(slow->next != fast ->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast ->next = NULL;
    return fast;
}
void limited_reverse(node*&head,int k){
    node * temp = head;
    while(k>0){
        temp = temp->next;
        --k;
    }
    node *f = head;
    
}
node *kreverse(node *head,int k){
    if(head==NULL){
        return NULL;
    }
    node *c = head;
    node*n = NULL;
    node *p = NULL;
    int cnt=0;
    while(c!=NULL && cnt<k){
        n = c->next;
        c->next=p;
        p = c;
        c=n;
        cnt++;
    }
    if(n!=NULL){
        head->next = kreverse(n,k);
    }
    return p;
}
int main()
{
    int n,k;
    cin>>n>>k;
    node*head=NULL;
    for(int i =0;i<n;i++){
        int data;
        cin>>data;
        tail_insert(head,data);
    }
    head = kreverse(head,k);
    print(head);
}