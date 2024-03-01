#pragma once

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Node.hpp"
#include "TreePrinter.hpp"

class AVLTree
{
    private:
        Node* _root;

        void DeleteTree(Node* current);
    public:
        AVLTree();
        ~AVLTree();

        void Insert(int key);
        void Remove(int key);

        void Print();
};

#endif