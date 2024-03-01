#include <iostream>

#include "AVLTree.hpp"
#include "TreePrinter.hpp"

#define SUCCESS 0

int main(int argc, char const *argv[])
{
    int countOperations;
    char option;
    int key;

    AVLTree* tree = new AVLTree();

    std::cin >> countOperations;

    for(int i = 0; i < countOperations; i++)
    {
        std::cin >> option;
        std::cin >> key;

        if (option == 'i')
        {
            std::cout << "AA";
        }
        else
        {
            tree->Remove(key);
        }
            
    }

    tree->Print();

    delete tree;

    return SUCCESS;
}