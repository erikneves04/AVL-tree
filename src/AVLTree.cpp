#include "AVLTree.hpp"
#include <iostream>

AVLTree::AVLTree() : _root(nullptr) {}

AVLTree::~AVLTree()
{
    DeleteTree(_root);
}

void AVLTree::DeleteTree(Node* current)
{
    if (current == nullptr)
        return;

    DeleteTree(current->Left);
    DeleteTree(current->Right);

    delete current;
}

int Height(Node* node)
{
    if (node == nullptr)
        return 0;

    return node->Height;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->Key = key;
    node->Left = nullptr;
    node->Right = nullptr;
    node->Height = 1;

    return node;
}

Node* RightRotate(Node* y)
{
    Node* x = y->Left;
    Node* T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    y->Height = Max(Height(y->Left), Height(y->Right)) + 1;
    x->Height = Max(Height(x->Left), Height(x->Right)) + 1;

    return x;
}

Node* LeftRotate(Node* x)
{
    Node* y = x->Right;
    Node* T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    x->Height = Max(Height(x->Left), Height(x->Right)) + 1;
    y->Height = Max(Height(y->Left), Height(y->Right)) + 1;

    return y;
}

int GetBalance(Node* node)
{
    if (node == nullptr)
        return 0;

    return Height(node->Left) - Height(node->Right);
}

Node* insert(Node* node, int key)
{
    if (node == nullptr)
        return newNode(key);

    if (key < node->Key)
        node->Left = insert(node->Left, key);
    else if (key > node->Key)
        node->Right = insert(node->Right, key);
    else
        return node;

    node->Height = 1 + Max(Height(node->Left), Height(node->Right));

    int balance = GetBalance(node);

    if (balance > 1 && key < node->Left->Key)
        return RightRotate(node);

    if (balance < -1 && key > node->Right->Key)
        return LeftRotate(node);

    if (balance > 1 && key > node->Left->Key)
    {
        node->Left = LeftRotate(node->Left);
        return RightRotate(node);
    }

    if (balance < -1 && key < node->Right->Key)
    {
        node->Right = RightRotate(node->Right);
        return LeftRotate(node);
    }

    return node;
}

void AVLTree::Insert(int key)
{
    _root = insert(_root, key);
}

Node* MinValueNode(Node* node)
{
    Node* current = node;

    while (current->Left != nullptr)
        current = current->Left;

    return current;
}

Node* DeleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->Key)
        root->Left = DeleteNode(root->Left, key);
    else if (key > root->Key)
        root->Right = DeleteNode(root->Right, key);
    else
    {
        if ((root->Left == nullptr) || (root->Right == nullptr))
        {
            Node* temp = root->Left ? root->Left : root->Right;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }

            delete (temp);
        }
        else
        {
            Node* temp = MinValueNode(root->Right);
            root->Key = temp->Key;
            root->Right = DeleteNode(root->Right, temp->Key);
        }
    }

    if (root == nullptr)
        return root;

    root->Height = 1 + Max(Height(root->Left), Height(root->Right));
    int balance = GetBalance(root);

    if (balance > 1 && GetBalance(root->Left) >= 0)
        return RightRotate(root);

    if (balance > 1 && GetBalance(root->Left) < 0)
    {
        root->Left = LeftRotate(root->Left);
        return RightRotate(root);
    }

    if (balance < -1 && GetBalance(root->Right) <= 0)
        return LeftRotate(root);

    if (balance < -1 && GetBalance(root->Right) > 0)
    {
        root->Right = RightRotate(root->Right);
        return LeftRotate(root);
    }

    return root;
}

void AVLTree::Remove(int key)
{
    _root = DeleteNode(_root, key);
}

void AVLTree::Print()
{
    TreePrinter printer;

    printer.PreFixed(_root);
    std::cout << std::endl;

    printer.InFixed(_root);
    std::cout << std::endl;

    printer.PostFixed(_root);
    std::cout << std::endl;
}