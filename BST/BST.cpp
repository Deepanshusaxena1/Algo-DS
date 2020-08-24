#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
bool find(struct Node *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    else if (root->data > data)
        return find(root->left, data);
    else
        return find(root->right, data);
}
Node *maximum(struct Node *root)
{
    while (root->right)
        root = root->right;
    return root;
}
Node *minimum(struct Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}
void Inorder(struct Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        struct Node *node = new Node(data);
        return node;
    }
    if (root->data > data)
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);
    return root;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    Inorder(root);
}