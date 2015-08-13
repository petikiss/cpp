#ifndef LISTA_H
#define LISTA_H

#include <iostream>



template <class T>
class Lista
{
  public:
    Lista() : m_root( new Node(0) ) {}
    ~Lista() { delete m_root; }
    void push_back(T data);
    void print();
  private:
    struct Node
    {
        Node (T data, Node* next = 0) : m_data(data), m_next(next) {}
        ~Node() { delete m_next; }
        T m_data;
        Node* m_next;
    };

    Node *m_root;
};



template <class T>
void Lista<T>::push_back(T data)
{
    Node* ptr = m_root;
    while (ptr->m_next != 0)
    {
        ptr = ptr->m_next;
    }

    Node* n = new Node(data);
    ptr->m_next = n;
}



template <class T>
void Lista<T>::print()
{
    Node* ptr = m_root->m_next;
    while (ptr != 0)
    {
        std::cout << ptr->m_data << "\n";
        ptr = ptr->m_next;
    }
}









#endif
