/*
Depth first search traversal for a binary tree.
Three methods are implemented.
1. Inorder: left, root, right
2. Preorder: root, left, right
3. Postorder: left, right, root
*/

#include <iostream>
#include<queue>

using namespace std;


class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }

        void add_left_child(Node* lft)
        {
            left = lft;
        }

        void add_right_child(Node* rht)
        {
            right = rht;
        }

        void add_both_children(Node* lft, Node* rht)
        {
            left = lft;
            right = rht;
        }
};

Node* createNode(int value)
{
    Node* node = new Node(value);
    return node;
}

void printInorder(Node* node)
{
    if(node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node * node)
{
    if(node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node * node)
{
    if(node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main()
{
    Node *root = createNode(1);
    root->add_both_children(createNode(2), createNode(3));
    root->left->add_both_children(createNode(4), createNode(5));
    cout << "Inorder traversal of the binary tree is " << endl;
    printInorder(root);
    cout << endl<< "Preorder traversal of the binary tree is " << endl;
    printPreorder(root);
    cout << endl<< "Postorder traversal of the binary tree is " << endl;
    printPostorder(root);
    return 0;
}
