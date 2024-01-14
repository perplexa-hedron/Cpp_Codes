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
    node *prev;
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};