#ifndef SET_H
#define SET_H

#include <list>
#include <algorithm>


template <class T>
class set
{
  public:
    set();
    ~set();
    set(const set<T>& s);
    set<T>& put(T data);
    set<T>& del(T data);
    unsigned int size();
    bool has(T data) const;
    set<T>& operator+=(const T& data);
    const set<T> operator+(const set<T>& other) const;
  private:
    std::list<T> m_list;
};



template <class T>
set<T>& set<T>::put(T data)
{
    // filter duplicate data
    if ( !has(data) )
    {
        m_list.push_back(data);
    }

    return *this;
}


template <class T>
unsigned int set<T>::size()
{
    return m_list.size();
}



template <class T>
set<T>& set<T>::del(T data)
{
    m_list.remove(data);
    return *this;
}


template <class T>
set<T>::set()
{
}


template <class T>
set<T>::~set()
{
}


template <class T>
set<T>::set(const set<T>& s)
{
    m_list = s.m_list;
}


template <class T>
bool set<T>::has(T data) const
{
    typename std::list<T>::const_iterator it = std::find(m_list.begin(), m_list.end(), data);
    if (it == m_list.end() )
    {
        return false;
    }

    return true;
}


template <class T>
set<T>& set<T>::operator+=(const T& data)
{
    return put(data);
}


template <class T>
const set<T> set<T>::operator+(const set<T>& other) const
{
    set<T> result = other;

    for( typename std::list<T>::const_iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
        result += *it;
    }

    return result;
}

#endif
