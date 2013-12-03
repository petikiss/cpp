#ifndef VALVEC_H
#define VALVEC_H

#include <list>



template <class T>
class valvec
{
  public:
    void push_back(T data);
    void inval(int index);
    void val(int index);
    T at(const int& index) const;
    T operator[](const int& index) const;
    T operator+=(const int& index);
    unsigned int size();
    void pop_back();

    class const_iterator : public std::list< std::pair<bool,T> >::const_iterator // space is necessary in nested class
    {
      public:
        const_iterator& operator++() {}
    };

    const_iterator begin() const { return m_list.begin(); }
    const_iterator end() const { return m_list.end(); }
  private:
    typedef std::pair<bool, T> PAIR;
    std::list<PAIR> m_list;
};




template <class T>
void valvec<T>::push_back(T data)
{
    PAIR p = std::make_pair(true,data);
    m_list.push_back(p);
}


template <class T>
void valvec<T>::inval(int index)
{
    int count = 0;
    for (typename std::list<PAIR>::iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
        //if (it->first == true)
        {
            if (count == index)
            {
                it->first=false;
                //std::cout << "asdf: "<< it->first << " " << it->second << std::endl;
            }
            count++;
        }
    }
}


template <class T>
void valvec<T>::val(int index)
{
    int count = 0;
    for (typename std::list<PAIR>::iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
        //if (it->first == true)
        {
            if (count == index)
            {
                it->first=true;
            }
            count++;
        }
    }
}



template <class T>
T valvec<T>::at(const int& index) const
{
    int count = 0;
    for (typename std::list<PAIR>::const_iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
        if(it->first == true)
        {
            if (count == index)
            {
                return it->second;
            }
            count++;
        }
    }
}


template <class T>
T valvec<T>::operator[](const int& index) const
{
    return at(index);
}


template <class T>
unsigned int valvec<T>::size()
{

    int count = 0;
    for (typename std::list<PAIR>::iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
        if (it->first == true)
        {
            count++;
        }
    }

    return count;
}


template <class T>
void valvec<T>::pop_back()
{

    typename std::list<PAIR>::iterator lastIt = m_list.begin();

    for (typename std::list<PAIR>::iterator it = m_list.begin();
         it != m_list.end();
         it++)
    {
         if (it->first == true)
         {
             lastIt = it;
         }
    }

    m_list.remove(*lastIt);
}


// template <class T>
// T valvec<T>::operator+=(const int& index)
// {
//     //return at(index);
// }



#endif
