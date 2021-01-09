/*
C++ program to create a linked list
*/

#include <iostream>
#include <cstdio>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print_linked_list(Node*);

int main()
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_linked_list(first);
    return 0;
}

void print_linked_list(Node* n)
{
    while(n != NULL)
    {
        cout << n->data << " ";
        n = n-> next;
    }

}