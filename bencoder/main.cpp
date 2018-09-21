// https://hackage.haskell.org/package/bencoding-0.2.1.0/candidate/docs/Data-BEncode.html#g:3
// https://en.wikipedia.org/wiki/Bencode
// https://wiki.theory.org/index.php/BitTorrentSpecification
// https://chocobo1.github.io/bencode_online/


#include "Tokens.hh"

#include <fstream>
#include <iostream>
#include <assert.h>


// declarations
Tokens::Bencode* readBencode(std::ifstream& inp);


bool isDigit( char c )
{
   return ( '0' <= c && c <= '9' );
}

Tokens::Str*
readStr(std::ifstream& inp)
{
    std::cout << "Read Str" << std::endl;

    // read string length at first
    std::string length = "";
    char ch = inp.get();
    std::cout << "CH: " << ch << std::endl;
    while (isDigit(ch))
    {
        length += ch;
        ch = inp.get();
    }

    assert(ch == ':');

    std::string str = "";
    for (int i = 0; i < atoi(length.c_str()); ++i)
    {
        ch = inp.get();
        str += ch;
    }


    std::cout << "str len: " << length << std::endl;
    std::cout << "str: " << str << std::endl;

    return new Tokens::Str(str);
}


Tokens::Dict*
readDict(std::ifstream& inp)
{
    std::cout << "Read Dict\n";

    // remove 'd' character
    assert(inp.get() == 'd');

    Tokens::Dict* dict = new Tokens::Dict();

    Tokens::Str* str = readStr(inp);
    Tokens::Bencode* bencode = readBencode(inp);

    dict->mDict[str] = bencode;

    return dict;
}


void createList(Tokens::Bencode* bencode)
{
    // remove 'd' character
//    assert(inp.get() == 'l');

}

Tokens::Bencode*
readBencode(std::ifstream& inp)
{
    std::cout << "readBencode" << std::endl;

    Tokens::Bencode* bencode;

    // check the next character without removing from the stream
    char ch = inp.peek();
    if (ch == 'd')
    {
        bencode = readDict(inp);
    }
    else if(ch == 'l')
    {
        assert("Not implemented LIST" == "0");
    }
    else if (ch == 'i')
    {
        assert("Not implemented INTEGER" == "0");
    }
    else if ( isDigit(ch))
    {
        bencode = readStr(inp);
    }
    else
    {
        assert(ch == 'e');
    }



    return bencode;
}


int main()
{
// archlinux-2018.09.01-x86_64.iso.torrent


std::ifstream inp;

// inp.open("archlinux-2018.09.01-x86_64.iso.torrent");
inp.open("test2.txt");

if (inp.fail())
{
    std::cout << "File opening error\n";
    return 1;
}

Tokens::Bencode* bencode;


bencode = readBencode(inp);

std::cout << std::endl << std::endl << std::endl << std::endl;
std::cout << "-----------------" << std::endl;
std::cout << "Bencode printing:" << std::endl;
bencode->print();

}
