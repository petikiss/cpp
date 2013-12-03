#ifndef SV_H
#define SV_H


#include <list>
#include <iostream>


template <class T, class U>
class SortedVector
{
};



template <class T>
class SortedVector
{
  public:
    void insert(T data);
    // T at(int pos) const;
    // T operator[](int pos) const;
    // int size() const;
    // typename std::list<T>::const_iterator begin() const {return m_list.begin(); }
    // typename std::list<T>::const_iterator end() const { return m_list.end(); }

    void kiir() const;
  private:
    std::list<T> m_list;
};



template <class T, class U = std::binary_function<int, int, bool> >
void SortedVector<T>::insert(T data)
{
    typename std::list<T>::iterator it = m_list.begin();
    bool found = false;

    if (m_list.empty())
    {
        m_list.push_back(data);
    }
    else
    {
        while(it != m_list.end() && !found)
        {
            if (data < *it)
            {
                m_list.insert(it, data);
                found = true;
            }
            it++;
        }

        if (!found)
        {
            m_list.push_back(data);
        }
    }
}


/*
template <class T>
T SortedVector<T>::at(int pos) const
{
    typename std::list<T>::const_iterator it = m_list.begin();

    int i = 0;
    while (it != m_list.end())
    {
        if (pos == i)
            return *it;

        i++;
        it++;
    }

    return T();
}


template <class T>
T SortedVector<T>::operator[](int pos) const
{
    return at(pos);
}


template <class T>
int SortedVector<T>::size() const
{
    return m_list.size();
}



template <class T>
void SortedVector<T>::kiir() const
{
    std::cout << "Adatok: ";
    for(typename std::list<T>::const_iterator it = m_list.begin();
         it != m_list.end();
         it++)
     {
         std::cout <<  *it << " ";
     }
}
*/

#endif
