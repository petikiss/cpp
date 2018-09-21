#ifndef TOKENS_HH
#define TOKENS_HH

#include <string>
#include <map>
#include <list>

#include <iostream>

namespace Tokens
{

class Bencode
{
public:
    virtual void print() = 0;
};

class Int : public Bencode
{
public:
    void print() {std::cout << mInt;}
//private:
    int mInt;
};

class Str : public Bencode
{
public:
    Str() {}
    Str(std::string str) : mStr(str) {}
    void print() {std::cout << mStr;}
//private:
    std::string mStr;
};

class Dict : public Bencode
{
public:
    void print()
    {
        for( auto i : mDict)
        {
            std::cout << "{";
            i.first->print();
            std::cout << ":";
            i.second->print();
            std::cout << "}";
        }
        std::cout << std::endl;
    }

//private:
    std::map<Str*, Bencode*> mDict;
};

class List : public Bencode
{
public:
    void print() {}
//private:
    std::list<Bencode*> mList;
};




}
#endif
