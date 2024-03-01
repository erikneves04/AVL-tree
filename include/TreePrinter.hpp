#pragma once

#ifndef TREEPRINTER_HPP
#define TREEPRINTER_HPP

#include "Node.hpp"

class TreePrinter
{
    public:
        void PreFixed(Node* node);
        void InFixed(Node* node);
        void PostFixed(Node* node);
};

#endif