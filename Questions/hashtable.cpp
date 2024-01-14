#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;
    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = nullptr;
    }
    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};
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
template <typename T>
class hashtable
{
    Node<T> **table;
    int current_size;
    int table_size;
    int hashfn(string key){
        int idx =0;
        int p=1;
        for(int i =0;i<key.length();i++){
            idx = idx + (key[i]*p)%table_size;
            idx = idx%table_size;
            p=(p*27) % table_size;
        }
        return idx;
    }
    void rehash(){
        Node <T> ** oldtable = table;
        int oldtablesize = table_size;
        table_size = 2*table_size;
        table = new Node<T>*[table_size];
        for(int i =0;i<table_size;i++){
            table[i] = nullptr;
        }
        current_size = 0;

        for(int i =0;i<oldtablesize;i++){
            Node <T>*temp = oldtable[i];
            while(temp!=nullptr){
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldtable[i] != nullptr){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
public:
    hashtable(int ts = 7)
    {
        table_size = ts;
        table = new Node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] =  nullptr;
        }
    }

    void insert(string key,T value){
        int idx = hashfn(key);
        Node <T> * n = new Node <T>(key,value);
        //insert at the head of the linked list with id=idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;
        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.7){
            rehash();
        }
    }
    void print(){
        for(int i =0;i<table_size;i++){
            cout<<"bucket"<<i<<"->";
            Node<T>*temp = table[i];
            while(temp!= nullptr){
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T* search (string key){
        int idx = hashfn(key);
        Node<T>*temp = table[idx];
        while(temp!= NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void erase(string key){
        int idx = hashfn(key);
        Node<T>*temp = table[idx];
        while(temp!= NULL){
            if(temp->next->key==key){
                delete temp->next;
                temp->next = nullptr;
                return;
            }
            temp = temp->next;
        }
        return;
    }
};
class student{
    public:
    string first_name;
    string last_name;
    string roll_no;
    student(string f,string l,string no){
        first_name = f;
        last_name = l;
        roll_no = no;
    }

    bool operator==(const student &s) const{
        return roll_no == s.roll_no;
    }
};
class hashfn{
    public:
    size_t operator()(const student &s) const{
        return s.first_name.length()+s.last_name.length();
    }
};
int main()
{
    
    //custon class implementation
    // unordered_map<student,int,hashfn> student_map;
    // student s1("Prateek","Narang","010");
    // student s2("Rahul","Kumar","023");
    // student s3("Prateek","Gupta","030");
    // student s4("Rahul","Kumar","120");
    // student_map[s1] = 100;
    // student_map[s2] = 120;
    // student_map[s3] = 11;
    // student_map[s4] = 45;

    // for(auto it: student_map){
    //     cout<<it.first.first_name<<" "<<it.first.last_name<<" : "<<it.first.roll_no<<" having marks = "<<it.second<<endl;
    // }

    //using hash class created 
    // hashtable<int> price_menu;
    // price_menu.insert("burger",120);
    // price_menu.insert("pepsi",20);
    // price_menu.insert("pizza",120);
    // price_menu.insert("noodles",120);
    // price_menu.insert("coke",120);

    // price_menu.print();
    // int *price = price_menu.search("noodles");
    // if(price == nullptr){
    //     cout<<"Not Found";
    // }
    // else{
    //     cout<<"price is "<<*price<<endl;
    // }
    return 0;
}