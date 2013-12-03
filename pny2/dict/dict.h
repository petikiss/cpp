#ifndef DICT_H
#define DICT_H

#include <map>

using namespace std;

template <class T>
class bad_index
{
  public:
    bad_index() {}
    bad_index(T index) {m_index = index;}
    T index() {return m_index;}
  private:
    T m_index;
};

template <class T, class L>
class dict
{
  public:
    void put(T key, L value);
    L get(T key) const;
    L operator[](T key) const;
    L& operator[](T key);
  private:
    std::map<T,L> m_map;
};



template <class T, class L>
void dict<T,L>::put(T key, L value)
{
    m_map[key] = value;
}



template <class T, class L>
L dict<T, L>::get(T key) const
{
    typename std::map<T, L>::const_iterator it = m_map.find(key);

    if ( it != m_map.end() )
    {
        return it->second;
    }
    else
    {
        throw bad_index<T>(key);
    }
}


template <class T, class L>
L dict<T, L>::operator[](T key) const
{
    return get(key);
}


template <class T, class L>
L& dict<T, L>::operator[](T key)
{
    typename std::map<T, L>::iterator it = m_map.find(key);

    if (it == m_map.end())
    {
        throw bad_index<T>(key);
    }

    return m_map[key];
}


#endif
