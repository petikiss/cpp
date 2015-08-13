#ifndef BAG_H
#define BAG_H

#include <list>
#include <algorithm>


template <class T>
class bag
{
  public:
    bag();
    ~bag();
    bag(const bag&);
    void put(T data);
    int mul(T data) const;
    void remove(T data);
    //void bag<T>::remove_all(); // extra qualification 'bag<T>::' on member 'remove_all
    void remove_all(T data);
    T operator[](int index);
  private:
    std::list<T> m_list;
};

template <class T>
bag<T>::bag()
{
}

template <class T>
bag<T>:: ~bag()
{
}

template <class T>
bag<T>::bag(const bag& rhs)
{
    m_list = rhs.m_list;
}


template <class T>
void bag<T>::put(T data)
{
    m_list.push_back(data);
}


template <class T>
int bag<T>::mul(T data) const
{
    int count =0;
    for ( typename std::list<T>::const_iterator it = m_list.begin();
          it != m_list.end();
          it++ )
    {
        if (*it == data)
            count++;
    }
    return count;
}


template <class T>
void bag<T>::remove(T data)
{
    typename std::list<T>::iterator it = std::find(m_list.begin(), m_list.end(), data);

    if (it != m_list.end())
        m_list.erase(it);
}



template <class T>
void bag<T>::remove_all(T data)
{
    m_list.remove(data);
}


template <class T>
class bad_value
{
  public:
    bad_value(int val) : m_val(val) {}
    T value() { return m_val;}
  private:
    T m_val;
};


template <class T>
T bag<T>::operator[](int index)
{
    int count =0;
    for ( typename std::list<T>::const_iterator it = m_list.begin();
          it != m_list.end();
          it++ )
    {
        if (count == index)
        {
            return *it;
        }
        else
        {
            count++;
        }
    }
    throw bad_value<T>(index);
}




#endif
