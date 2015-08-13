#ifndef BINTREE_H
#define BINTREE_H


#include <iostream>

template <class T>
class BinTree
{
  public:
    BinTree() : m_root(0) {}
    void addNode(T value);
    void print();
  private:
    struct Node
    {
        Node(T value, Node* left = 0, Node* right = 0) : m_value(value), m_left(left), m_right(right) {}
        T m_value;
        Node* m_left;
        Node* m_right;
      private:
        Node();
    };
    void add(T value, Node*& node);
    void preorder(Node* node);
    Node* m_root;
};



template <class T>
void BinTree<T>::addNode(T value)
{
    // first element
    if (!m_root)
    {
        m_root = new Node(value);
    }
    else
    {
        add(value, m_root);
    }
}


template <class T>
void BinTree<T>::add(T value, Node*& node)
{
    // insert left
    if (value <= node->m_value)
    {
        if (!node->m_left)
        {
            node->m_left = new Node(value);
        }
        else
        {
            add(value, node->m_left);
        }
    }
    else // insert right
    {
        if (!node->m_right)
        {
            node->m_left = new Node (value);
        }
        else
        {
            add(value, node->m_right);
        }
    }
}


template <class T>
void BinTree<T>::print()
{
    if (m_root)
    {
        preorder(m_root);
    }
}


template <class T>
void BinTree<T>::preorder(Node* node)
{
     std::cout << node->m_value << " ";

     if (node->m_left)
     {
         preorder(node->m_left);
     }

     if (node->m_right)
     {
         preorder(node->m_right);
     }
}

#endif
