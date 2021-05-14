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

void printLevelOrder(Node* root)
{
    if(root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false)
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node->left !=NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }

}

int main()
{
    Node *root = createNode(1);
    root->add_both_children(createNode(2), createNode(3));
    root->left->add_both_children(createNode(4), createNode(5));
    cout << "Level Order traversal of the binary tree is " << endl;
    printLevelOrder(root);
    return 0;
}
