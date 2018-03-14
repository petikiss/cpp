#ifndef VECTOR_H
#define VECTOR_H

#include <memory>



class Vector
{
private:
    struct Node
    {
        Node(int data, std::shared_ptr<Node> next = nullptr, std::shared_ptr<Node> prev = nullptr) : _data(data), _next(next), _prev(prev) {}
        int _data;
        std::shared_ptr<Node> _next;
        std::shared_ptr<Node> _prev;
    };

    std::shared_ptr<Node> _root;
    std::shared_ptr<Node> _lastNode;
public:
    class Iterator
    {
        public:
            Iterator(std::shared_ptr<Node> node) : _node(node) {}
            int operator*() { return _node->_data;}
            bool operator!=(Iterator it) {return _node != it._node; }
            // Iterator operator++() {return Iterator(_node->_next);}
            Iterator operator++() {_node = _node->_next; return *this;}
        private:
            std::shared_ptr<Node> _node;
    };


    void push_back(int data);
    void push_front(int data);
    void print();

    Iterator begin() { return Iterator(_root); }
    Iterator end() { return Iterator(_lastNode->_next); }
    //Iterator remove( Iterator it) { (it->_prev)->_next = it->_next;}
};



#endif // VECTOR_H
