#include "vector.h"

#include <iostream>

void Vector::push_back(int data)
{
    std::shared_ptr<Node> tmpNode = std::make_shared<Node>(data);

    if (_root == nullptr)
    {
        _root = tmpNode;
    }
    else
    {
        tmpNode->_prev = _lastNode;
        _lastNode->_next = tmpNode;
    }

    _lastNode = tmpNode;
}


void Vector::push_front(int data)
{
    std::shared_ptr<Node> tmpNode = std::make_shared<Node>(data, _root);

    if (_root == nullptr)
    {
        _lastNode = tmpNode;
    }
    else
    {
        _root->_prev = tmpNode;
    }

    _root = tmpNode;
}


void Vector::print()
{
    std::shared_ptr<Node> p = _root;

    while ( p != nullptr)
    {
        std::cout << p->_data << std::endl;

        p = p->_next;
    }
}
