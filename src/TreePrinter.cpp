#include <iostream>

#include "Node.hpp"
#include "TreePrinter.hpp"

void TreePrinter::PreFixed(Node* node)
{
    if (node == nullptr)
        return;

    std::cout << node->Key << " ";

    PreFixed(node->Left);
    PreFixed(node->Right);
}

void TreePrinter::InFixed(Node* node)
{
    if (node == nullptr)
        return;

    InFixed(node->Left);

    std::cout << node->Key << " ";

    InFixed(node->Right);  
}

void TreePrinter::PostFixed(Node* node)
{
    if (node == nullptr)
        return;

    PostFixed(node->Left);
    PostFixed(node->Right);

    std::cout << node->Key << " ";
}