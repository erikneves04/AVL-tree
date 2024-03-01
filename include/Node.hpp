#pragma once

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    public:
        int Key;
        int Height = 0; 

        Node* Left;
        Node* Right;
};

#endif